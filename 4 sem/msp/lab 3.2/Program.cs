using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите двоичное число для кодирования:\n");
            string s = Console.ReadLine();
            Console.Write("Введите ключ:\n");
            int key = Convert.ToInt32(Console.ReadLine(), 2);
            int izm = (Convert.ToInt32(s, 2) ^ key);
            Console.WriteLine("Закодированный код: {0}", Convert.ToString(izm, 2));
            Console.WriteLine("Декодированный код: {0}", Convert.ToString(izm^key, 2));
            Console.ReadKey();
        }
    }
}
