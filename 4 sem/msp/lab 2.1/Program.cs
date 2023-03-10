using System;
namespace ConsoleApplab2_1
{
    class Program
    {
        static void Main()
        {
            double m, et, mdf = 0, x=0;
            Console.Write("Введите m: ");
            m = Convert.ToDouble(Console.ReadLine());
            for (double otr = 0; otr <= 2 * Math.PI; otr += (Math.PI) / 50)//размеры отрезка
            {
                double f = 1.0 / 2;
                for (double i = 1; i <= m; i++)
                {
                    f += ((1.0 + Math.Pow((-1), (i + 1))) / (Math.PI * i)) * Math.Sin(i * otr);
                }
                if (otr <= Math.PI)
                    et = 1;
                else
                    et = 0;
                if (Math.Abs(et - f) > mdf)
                {
                    mdf = Math.Abs(et - f);
                    x = otr;
                }
            }
            Console.WriteLine("Максимальная разность = " + mdf.ToString());
            Console.WriteLine("При x = " + (x / Math.PI).ToString() + " pi");
            Console.ReadKey();
        }
    }
}