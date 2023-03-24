using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] z = new string[] { "11", "10", "000", "0010", "011", "001", "01011", "01010" };
            char key;
            do
            {
                Console.WriteLine("Выберете команду:\n1 - Ввод слова для кодирования\n2 - Ввод слова для декодирования\n3 - Вывод словаря\n4 - Выход\n");
                key = Console.ReadKey().KeyChar;
                switch (key)
                {
                    case '1':
                        Console.Write("\nВведите слове для кодировки: ");
                        string cod = Console.ReadLine();
                        for (int i = 0; i < 8; i++)
                        {
                            cod = cod.Replace("z" + (i + 1).ToString(),
                            z[i]);
                        }
                        Console.WriteLine("\nЗакодированное слово: {0}", cod);
                        break;
                    case '2':
                        Console.Write("\nВведите слове для декодировки: ");
                        string decod = Console.ReadLine(),buff = ""; 
                        while (decod.Length != 0)
                            for (int i = 0; i < 8; i++)
                                if (decod.StartsWith(z[i]))
                                {
                                    decod = decod.Remove(0, z[i].Length);
                                    buff += "z" + (i + 1).ToString();
                                }
                        Console.WriteLine("\nДекодированное слово: {0}", buff);
                        break;
                    case '3':
                        Console.WriteLine();
                        for (int i = 0; i < z.Length; i++)
                            Console.WriteLine("z{0} = {1}",i , z[i]);
                        Console.WriteLine();
                        break;
                    case '4':
                        break;
                }
            } while (key != '4');
        }
    }
}

