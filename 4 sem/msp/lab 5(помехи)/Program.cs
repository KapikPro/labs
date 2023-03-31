using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n, s = 0;
            Console.WriteLine("введите количество цифр в матрице, кратное 3");
            n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("введите двоичную матрицу");
            int[,] a = new int[n / (n / 3)+1, n/3+1];
            for (int t = 0; t < n/(n/3); t++)
                for (int i = 0; i < n / 3; i++)
                {
                    a[t,i]=Convert.ToInt32(Console.ReadLine());
                    s += a[t,i];
                    if (i == (n / 3) - 1)
                    {
                        if (s % 2 != 0)
                            a[t,(n / 3)] = 1;
                        else
                            a[t,(n / 3)] = 0;
                        s = 0;
                    }
                }
            for (int i = 0; i < n / 3; i++)
                for (int t = 0; t < n / (n / 3); t++)
                {
                    s += a[t, i];
                    if (t== n / (n / 3)-1)
                    {
                        if (s % 2 != 0)
                            a[n / (n / 3), i] = 1;
                        else
                            a[n / (n / 3), i] = 0;
                        s = 0;
                    }
                }
            Console.WriteLine("вывод матрицы:");
            for (int t = 0; t < n / (n / 3)+1; t++)
            {
                Console.Write('\n');
                for (int i = 0; i < n/3+1; i++)
                {
                    Console.Write($"{a[t,i]}");
                }
            }
            Console.Write('\n');
            Console.WriteLine("введите строку и столбец для добавления ошибки(начиная с 0)");
            int io1, io2, to1, to2;
            to1 = Convert.ToInt32(Console.ReadLine());
            io1 = Convert.ToInt32(Console.ReadLine());
            if (a[to1, io1] == 0)
                a[to1, io1] = 1;
            else
                a[to1, io1] = 0;
            Console.WriteLine("матрица с 1 ошибкой:");

            for (int t = 0; t < n / (n / 3) + 1; t++)
            {
                Console.Write('\n');
                for (int i = 0; i < n / 3 + 1; i++)
                {
                    Console.Write($"{a[t, i]}");
                }
            }
            for (int t = 0; t < n / (n / 3)+1; t++)
                for (int i = 0; i < n / 3 + 1; i++)
                {
                    s += a[t, i];
                    if (i == (n / 3) - 1)
                    {
                        if ((s + a[t, n / 3]) % 2 != 0)
                            to1 = t;
                        s = 0;
                        break;
                    }
                }
            for (int i = 0; i < n / 3 + 1; i++)
                for (int t = 0; t < n / (n / 3)+1; t++)
                {
                    s += a[t, i];
                    if (t == n / (n / 3) - 1)
                    {
                        if ((s + a[n/(n/3),i]) % 2 != 0)
                            io1 = i;
                        s = 0;
                        break;
                    }
                }
            if (a[to1, io1] == 0)
                a[to1, io1] = 1;
            else
                a[to1, io1] = 0;
            Console.WriteLine("матрица с исправленной ошибкой:");

            for (int t = 0; t < n / (n / 3) + 1; t++)
            {
                Console.Write('\n');
                for (int i = 0; i < n / 3 + 1; i++)
                {
                    Console.Write($"{a[t, i]}");
                }
            }
            Console.WriteLine("\nвведите строку и столбец для добавления первой ошибки(начиная с 0)");
            to1 = Convert.ToInt32(Console.ReadLine());
            io1 = Convert.ToInt32(Console.ReadLine());
            if (a[to1, io1] == 0)
                a[to1, io1] = 1;
            else
                a[to1, io1] = 0;
            Console.WriteLine("\nвведите строку и столбец для добавления второй ошибки(начиная с 0)");
            to2 = Convert.ToInt32(Console.ReadLine());
            io2 = Convert.ToInt32(Console.ReadLine());
            if (a[to2, io2] == 0)
                a[to2, io2] = 1;
            else
                a[to2, io2] = 0;
            Console.WriteLine("\nматрица с 2 ошибками:");

            for (int t = 0; t < n / (n / 3) + 1; t++)
            {
                Console.Write('\n');
                for (int i = 0; i < n / 3 + 1; i++)
                {
                    Console.Write($"{a[t, i]}");
                }
            }
            int k=0;
            int o1=io1, o2=io2,o3=to1,o4=to2; 
            
            for (int t = 0; t < n / (n / 3)+1; t++)
                for (int i = 0; i < n / 3+1; i++)
                {
                    s += a[t, i];
                    if (i == (n / 3) - 1)
                    {
                        if (s % 2 != 0)
                            if (k == 0)
                            {
                                to1 = t;
                                k++;
                            }
                            else
                            {
                                to2 = t;
                                s = 0;
                                k = 0;
                                break;
                            }
                        s = 0;
                        k = 0;
                    }
                }
            for (int i = 0; i < n / 3+1; i++)
                for (int t = 0; t < n / (n / 3) + 1; t++)
                {
                    s += a[t, i];
                    if (t == n / (n / 3) - 1)
                    {
                        if (s % 2 != 0)
                            if (k == 0)
                            {
                                io1 = t;
                                k++;
                            }
                            else
                            {
                                io2 = t;
                                s = 0;
                                k = 0;
                                break;
                            }
                        s = 0;
                        k = 0;
                    }
                }
            io1 = o1; io2 = o2; to1 = o3; to2 = o4;

            Console.WriteLine("/nошибки найдены в строках:");
            if (to1 >= 0 && to2 >= 0)
            {
                Console.WriteLine(to2 + " " + to1);
            }
            else
                if (to1 >= 0)
                Console.WriteLine(to1);
            else
                Console.WriteLine(to2);

            Console.WriteLine("и в столбцах:");
            if (io1 >= 0 && io2 >= 0)
            {
                Console.WriteLine(io2 + " " + io1);
            }
            else
                if (io1 >= 0)
                Console.WriteLine(io1);
            else
                Console.WriteLine(io2);
        }
    }
}
