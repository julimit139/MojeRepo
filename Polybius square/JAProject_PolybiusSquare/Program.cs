﻿using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace JAProject_PolybiusSquare
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        /// 

        private const string cpp_dll_name = "PolybiusSquareCpp.dll";
        private const string asm_dll_name = "PolybiusSquareASM.dll";

        [DllImport(cpp_dll_name)]
        public static extern bool checkLengthOfKeyword(byte[] keyword);

        [DllImport(cpp_dll_name)]
        public static extern bool checkCharactersInKeyword(byte[] keyword);

        [DllImport(cpp_dll_name)]
        public static extern bool checkDuplicatesInKeyword(byte[] keyword);

        [DllImport(cpp_dll_name)]
        public static extern string removeDuplicates(byte[] keyword);

        [DllImport(cpp_dll_name)]
        public static extern string checkValidityOfKeyword(byte[] keyword);

        [DllImport(cpp_dll_name)]
        public static extern void createPolybiusSquare(IntPtr square, byte[] keyword);

        [DllImport(cpp_dll_name)]
        public static extern bool checkCharactersInText(byte[] text);

        [DllImport(cpp_dll_name)]
        public static extern string checkValidityOfText(byte[] text);

        [DllImport(cpp_dll_name)]
        public static extern string encryptText(IntPtr square, byte[] text, int width, int height);



        [DllImport(asm_dll_name)]
        public static extern int testProc(int testInt);

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new mainWindow());
        }
    }
}
