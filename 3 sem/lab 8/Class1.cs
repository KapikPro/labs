using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_8
{
    delegate void OoO();

    interface Info
    {
        void Viv_Info();
    }
    interface Sost
    {
        void Viv_Sost();
    }

    abstract class Person : Info
    {
        public Person(string f, string i, string o)
        {
            _f = f;
            _i = i;
            _o = o;
        }
        public string get_f()
        {
            return _f;
        }
        public string get_i()
        {
            return _i;
        }
        public string get_o()
        {
            return _o;
        }
        public abstract void Viv_Info();
        private
        string _f;
        string _i;
        string _o;
    }

    class Student : Person, Sost
    {
        public Student(string f, string i, string o, string har) : base(f, i, o)
        {
            _har = har;
        }
        public override void Viv_Info()
        {
            Console.WriteLine("Вывод информации о студенте:");
            Console.WriteLine($"ФИО - {get_f()} { get_i()} { get_o()}");
        }
        public void Viv_Sost()
        {
            Console.WriteLine($"Вывод характеристики студента - { _har}");
        }
        private

            string _har;
    }

    class old : Person
    {
        public old(string f, string i, string o, float zarp) : base(f, i, o)
        {
            _zarp = zarp;
        }
        public float get_zarp()
        {
            return _zarp;
        }
        public override void Viv_Info()
        {

        }
        private
          float _zarp;

    }
    class Prep : old
    {
        public Prep(string f, string i, string o, float zarp, int stazh) : base(f, i, o, zarp)
        {
            _stazh = stazh;
        }
        public override void Viv_Info()
        {
            Console.WriteLine("Вывод информации о преподавателе:");
            Console.WriteLine($"ФИО - { get_f()} { get_i()} { get_o()}");
            Console.WriteLine($"Его зарплата = { get_zarp()} рублей");
            Console.WriteLine($"Его стаж составляет { _stazh } лет");
        }

        private
          int _stazh;
    }

    class Zav : old
    {
        public Zav(string f, string i, string o, float zarp,string kaf) : base(f, i, o, zarp)
        {
            _kaf = kaf; 
        }
        public override void Viv_Info()
        {
            Console.WriteLine("Вывод информации о заведующем кафедрой:");
            Console.WriteLine($"ФИО - { get_f()} { get_i()} { get_o()}");
            Console.WriteLine($"Его зарплата = { get_zarp()}");
            Console.WriteLine($"Он заведует кафедрой { _kaf}") ;
        }

        private
        string _kaf;
    }
}
