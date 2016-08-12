using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using MySql.Data;
using MySql.Data.MySqlClient;

namespace What
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sreader = new StreamReader("F:\\mindex_backup.txt", Encoding.Default);
            string constr = "server=XXX;User Id=XXX;password=XXX;Database=XXX";
            MySqlConnection mycon = new MySqlConnection(constr);
            mycon.Open();
            string musicID;
            string musicName;
            string musicType;
            string blankLine;
            while((blankLine=sreader.ReadLine())!=null)
            {
                if (blankLine.IndexOf('_') > 0) musicID = blankLine;
                else continue;
                musicName = sreader.ReadLine();
                musicType = sreader.ReadLine();

                Console.WriteLine("MusicID=" + musicID + " MusicName=" + musicName + " MusicType=" + musicType);
                MySqlCommand mycmd = new MySqlCommand("insert into infos values(\""+musicID+"\",\""+musicName+"\",\""+musicType+"\",\"unknown\")", mycon);
                mycmd.ExecuteNonQuery();
            }
            mycon.Close();
        }
    }
}
