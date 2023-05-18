using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml;


namespace RegExpLab
{
    class Program
    {
        static void Main()
        {
            /*string str = " фыидо, fjbld33- 2олт?";
            Console.WriteLine(str);
            Regex re = new Regex(@"."); 
            Regex re = new Regex(@"\w+");
            string input = Console.ReadLine();
            re = new Regex(@"(\W*)(\w+)(\W+)(\w+)(\W+)(\w+)(\W*)");
            Console.WriteLine(re.Replace(str, "$1$4$3$2$5$6$7"));
            re = new Regex(@"\S*[a-zA-Z]+\d+\S*");
            */

            string str_st;
            try
            {
                using (StreamReader sr = new StreamReader("CreateDB.sql"))
                {
                    str_st = sr.ReadToEnd();
                    Console.WriteLine(str_st.Length);
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка чтения файла: \" CreateDB.sql\"\n{0}", ex);
                Console.ReadLine();
                return;
            }

            string str1 = Regex.Replace(str_st, "GO", "");
            string str2 = Regex.Replace(str1, "SET.+\n*", "");
            string str3 = Regex.Replace(str2, @"\[.+\]\.\[(.+?)\]", "$1");
            string str4 = Regex.Replace(str3, @"\[(.+?)\]", "$1");
            string str5 = Regex.Replace(str4, @"IDENTITY\(1,1\)", "AUTO_INCREMENT");
            string str6 = Regex.Replace(str5, "timestamp", "timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP");
            string str7 = Regex.Replace(str6, "uniqueidentifier", "char(32)");
            string str8 = Regex.Replace(str7, @"xml|ntext|nvarchar\(max\)", "text");
            string str9 = Regex.Replace(str8, @"image|varbinary\(max\)", "BLOB");
            Regex re = new Regex(@"(?!\(\d+\))\(.+\)");
            MatchCollection mc = re.Matches(str_st);
            int count = 0;

            /*foreach (var m in mc)
            {
                Console.WriteLine(m);
                Console.WriteLine(++count);
            }
            string s6 = Regex.Replace(str6, @"CONSTRAINT .+ PRIMARY KEY CLUSTERED\n*\([\s\S]+?\)WITH \(PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON\) ON PRIMARY", "AAAAOOO",RegexOptions.Singleline);

            Console.WriteLine(s6);*/
            Console.ReadLine();
        }
    }
}
