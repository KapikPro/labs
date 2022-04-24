Unit  UnLab2;   // файл  UnLab2.pas
Interface

Type
  vv=(bus,taxi,train,plain);
  form = record
    vid:vv;
    mar:string[3];
    kol:integer;
  end;

//----------первая часть: создание типизированного файла в диалоге
Procedure CreateTypedFile1();

//----------вторая часть: создание типизированного файла из текстового
Procedure CreateTypedFile2();

//-------------- третья часть: поиск в типизированном файле ----
Procedure FindIVAN();

//-------------- просмотр типизированного файла ----
Procedure ViewFile();

Implementation // -----------реализационная часть-----------------

//----------первая часть: создание типизированного файла в диалоге
Procedure CreateTypedFile1();
var
  f: form;
  fr: file of form; // типизированный файл - файл записей
  n, kol,k: integer;
  ch: char;
  u:string;
  FileName:string[80];
begin
  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;
  FileName := ParamStr(1);
// или простой диалог или через параметры программы при её вызове ParamStr(1)
// writeln('Введите имя типизированного файла');
// readln(FileName);

  AssignFile(fr, FileName);
  Try  ReWrite(fr);    //  или  {$I-} ReWrite(fr); {$I+} и if IOResult<>0 then <ошибка>
  Except
    writeln('Error: не удалось создать типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  writeln('справка:');
  writeln('1-автобус');
  writeln('2-такси');
  writeln('3-поезд');
  writeln('4-самолет');
  repeat
    
    write('транспорт - '); readln(k); 
    f.vid:=vv(k-1);
    write('маршрут - ');     readln(f.mar);
    write('количество остановок до метро - ');  readln(f.kol);
    write(fr, f);   // запись записи целиком в файл
    inc(kol);

    write('Ещё? (y/n)'#13#10);
    readln(ch)
  until UpCase(ch)='N';

  CloseFile(fr);

  writeln('Создан типизированный файл из ',kol,' записей');
  write('Press ENTER');
  readln;
end;

//---------------------------------------------------------------------------------------
//----------вторая часть: создание типизированного файла из текстового
Procedure CreateTypedFile2();
var
  f: form;
  ft: TextFile; // текстовый файл
  fr: file of form; // типизированный файл - файл записей
  n, kol,k: integer;
ch: char;
FileName1, FileName2:string[80];
begin
  if ParamCount<2 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

FileName2:= Paramstr(2);
 // или простой диалог или через параметры программы при её вызове ParamStr(2)
// writeln('Введите имя текстового файла');
// readln(FileName); 

 AssignFile(ft, FileName2);
  Try  Reset(ft);
  Except
    writeln('Error: не удалось открыть текстовый файл ',Paramstr(2));
    write('Press ENTER'); readln;  exit
  end;

kol:=0;
FileName1:= Paramstr(1);
AssignFile(fr, FileName1);
rewrite(fr);
while not eof(ft) do
begin
readln(ft,k,f.mar,f.kol);
f.vid:=vv(k-1);
inc(kol);
write(fr, f);
end;

CloseFile(ft);
writeln('Создан типизированный файл из ',kol,' записей');
CloseFile(fr);
write('Press ENTER');
readln;
end;

//--------------------------------------------------------------
//-------------- третья часть: поиск в типизированном файле ----
Procedure FindIVAN();
var
  f: form;
  fr: file of form;
  kol,koli,kola, max,min,t: integer;
   mari,mara:string;
  naz,k:vv;
  FileName:string[80];
begin
  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
// или простой диалог или через параметры программы при её вызове ParamStr(1)
// writeln('Введите имя типизированного файла');
// readln(FileName); 

  AssignFile(fr, FileName);
Try  ReSet(fr);    //  или  {$I-} ReSet(fr); {$I+} if IOResult<>0 then
  Except
    writeln('Error: не удалось открыть типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit
  end;
  writeln('справка:');
  writeln('1-автобус');
  writeln('2-такси');
  writeln('3-поезд');
  writeln('4-самолет');
  write('введите искомый тип транспорта - ');
  readln(t);
  k:=vv(t-1);
  koli:=0;
  kola:=0;
  kol:=0;
  max:=-1;
  while not eof(fr) do
  begin
    read(fr, f);
    inc(kol);// считывание
    if(kol=1)then
  begin
  naz:=f.vid;
  min:=f.kol;
  koli:=kol;
  mari:=f.mar;
  end;
       // Если Иван c первого курса бакалавриата с хотя бы одной пятеркой
    if (f.vid = k )then
    begin
      writeln('найден маршрут ',f.mar,' для транспорта ',f.vid,' у которого ',f.kol, ' остановок до метро');
      if (f.kol>=max) then// сравнение в верхнем регистре
    begin
    max:=f.kol;
    kola:=kol;
    mara:=f.mar;
    end;
  end;
end;
  if max=-1 then
    writeln('Данные, соответствующие запросу, не найдены')
  else
  begin
  seek(fr,koli-1);
  f.vid:=k;
  f.kol:=max;
  f.mar:=mara;
  write(fr,f);
  seek(fr,kola-1);
  f.kol:=min;
  f.vid:=naz;
  f.mar:=mari;
  write(fr,f);
  end;
   writeln('изменённый список:');
   seek(fr,0);
    while not eof(fr) do
    begin
      read(fr, f);
       writeln('найден маршрут ',f.mar,' для транспорта ',f.vid,' у которого ',f.kol, ' остановок до метро');
    end;
  CloseFile(fr);

  write('Press ENTER');  readln;
end;
//--------------------------------------------------------------
//-------------- просмотр типизированного файла ----
Procedure ViewFile();
var
  f: form;
  fr: file of form;
  n, kol: integer;
  FileName:string[80];
begin
  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
// или простой диалог или через параметры программы при её вызове ParamStr(1)
// writeln('Введите имя типизированного файла');
// readln(FileName); 
AssignFile(fr, FileName);
  Try  ReSet(fr);    //  или  {$I-} ReSet(fr); {$I+} if IOResult<>0 then
  Except
    writeln('Error: не удалось открыть типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  while not eof(fr) do
  begin
    read(fr, f); // считывание

      writeln('найден маршрут ',f.mar,' для транспорта ',f.vid,' у которого ',f.kol, ' остановок до метро' );
      inc(kol);
  end;

  if kol=0 then
    writeln('Данные не найдены')
  else
    writeln('Найдено ',kol, ' записей');

  CloseFile(fr);

  write('Press ENTER');  readln;
end;

End.
