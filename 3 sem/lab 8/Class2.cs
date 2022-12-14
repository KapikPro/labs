using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
namespace lab_8
{
    public class Program
    {
        public static void Main(string[] args)
        {
            OoO? methods=null;
            string str,f,i,o,kaf,har;
            int uch=0, pr=0, zv=0;
            int a, b, k = 1, stazh=0;
            float zarp = 0;
            while (true)
            {
                Console.WriteLine("\nменю:");
                Console.WriteLine("1-добавить/переопределить ученика\n2-добавить/переопределить преподавателя\n3-добавить/переопределить заведущего кафедрой\n4-вывести всех добавленный вместе с их данными\n5-перезапустить программу\n");
                //(вывод производится с помощью многоадресного делегата, т.е. он сразу проверяется)
                while ((!int.TryParse(Console.ReadLine(), out a)) || (a != 1 && a != 2 && a != 3 && a != 4 && a != 5))
                    Console.WriteLine("вы ввели что-то страшное, повторите ввод\n");
                if (k == 0)
                    break;
                switch (a)
                {
                    case (1):
                   
                            Console.WriteLine("введите фамилию ученика");
                            f = Console.ReadLine();
                            while (!(new Regex("[а-я]+").IsMatch(f)))
                            {
                                Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                                f = Console.ReadLine();
                            }
                            Console.WriteLine("введите имя ученика");
                            i = Console.ReadLine();
                            while (!(new Regex("[а-я]+").IsMatch(i)))
                            {
                                Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                                i = Console.ReadLine();
                            }
                            Console.WriteLine("введите отчество ученика");
                            o = Console.ReadLine();
                            while (!(new Regex("[а-я]+").IsMatch(o)))
                            {
                                Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                                o = Console.ReadLine();
                            }
                            Console.WriteLine("введите характеристику ученика ученика(отличник, хорошист и т.п.)");
                            har = Console.ReadLine();
                            while (!(new Regex("[а-я]+").IsMatch(har)))
                            {
                                Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                                har = Console.ReadLine();
                            }
                            Student Alex = new Student(f, i, o,  har);  
                            methods += Alex.Viv_Info;
                            methods += Alex.Viv_Sost;

                        break;
                    case (2):
                        Console.WriteLine("введите фамилию преподавателя");
                        f = Console.ReadLine();
                        while (!(new Regex("[а-я]+").IsMatch(f)))
                        {
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                            f = Console.ReadLine();
                        }
                        Console.WriteLine("введите имя преподавателя");
                        i = Console.ReadLine();
                        while (!(new Regex("[а-я]+").IsMatch(i)))
                        {
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                            i = Console.ReadLine();
                        }
                        Console.WriteLine("введите отчество преподавателя");
                        o = Console.ReadLine();
                        while (!(new Regex("[а-я]+").IsMatch(o)))
                        {
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                            o = Console.ReadLine();
                        }
                        Console.WriteLine("введите зарплату преподавателя");
                        while (!float.TryParse(Console.ReadLine(), out zarp))
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                        Console.WriteLine("введите стаж преподавателя(целых лет)");
                        while (!int.TryParse(Console.ReadLine(), out stazh))
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                        Prep Bob = new Prep( f,  i,  o,  zarp,  stazh);
                        methods += Bob.Viv_Info;
                        break;
                    case (3):
                        Console.WriteLine("введите фамилию заведующего кафедры");
                        f = Console.ReadLine();
                        while (!(new Regex("[а-я]+").IsMatch(f)))
                        {
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                            f = Console.ReadLine();
                        }
                        Console.WriteLine("введите имя заведующего кафедры");
                        i = Console.ReadLine();
                        while (!(new Regex("[а-я]+").IsMatch(i)))
                        {
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                            i = Console.ReadLine();
                        }
                        Console.WriteLine("введите отчество заведующего кафедры");
                        o = Console.ReadLine();
                        while (!(new Regex("[а-я]+").IsMatch(o)))
                        {
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                            o = Console.ReadLine();
                        }
                        Console.WriteLine("введите зарплату заведующего кафедры");
                        while (!float.TryParse(Console.ReadLine(), out zarp))
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                        Console.WriteLine("введите кафедру заведующего");
                        kaf = Console.ReadLine();
                        while (!(new Regex("[а-я]+").IsMatch(kaf)))
                        {
                            Console.WriteLine("вы ввели что-то страшное(или на английском), повторите ввод");
                            kaf = Console.ReadLine();
                        }
                        Zav Igor = new Zav(f, i, o, zarp, kaf);
                        methods += Igor.Viv_Info;
                        break;
                    case (4):
                        if (methods != null)
                            methods.Invoke();
                        else
                            Console.WriteLine("студент, преподаватель и зав кафедры не созданы");
                        break;
                    case (5):
                        Main(args);
                        break;
                }
            
            }
        }
    }
}


