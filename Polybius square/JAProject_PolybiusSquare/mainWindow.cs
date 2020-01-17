using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace JAProject_PolybiusSquare
{
    public partial class mainWindow : Form
    {
        byte[][] square;

        public mainWindow()
        {
            square = new byte[5][];
            for(int i = 0; i < 5; i++)
            {
                square[i] = new byte[11];
            }
            InitializeComponent();
        }

        /*private void setLabel(string s)
        {
            textLabel.Text = s;
        }*/

        /*private void okButton_Click(object sender, EventArgs e)
        {
            setLabel(mySquare.checkLengthOfText(textBox.Text).ToString());
        }

        private void textBox_TextChanged(object sender, EventArgs e)
        {
            keywordTextBox.Text = textBox.Text;
        }*/

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void threadsLabel_Click(object sender, EventArgs e)
        {

        }

        private void encryptButton_Click(object sender, EventArgs e)
        {
            encryptedTextAnswerRichTextBox.Text = "123456789012345678901234567890123456789012345678901234567890123456789012345678912346718723198hkbajhsdksdaksdakjsdaksjdkbajsbdakjsbdakjsbdakjsbdakjsbdaksjbdakjsdbaksjdaksjbdakjsbdakjsbdakjsbdkajsbkjabdkjasbdkjabskjdabskjdabskdabskjdbajsdbajsbdkjabskjabdskjabskjdbaskjdbakjsbdaksjbdaksbdkajbdskj";
            //int testInt = 4;
            //encryptedTextAnswerRichTextBox.Text = Program.testProc(testInt).ToString();

            String keyword = "abcd";
            byte[] keywordArray = Encoding.ASCII.GetBytes(keyword);

            IntPtr initArray = Marshal.AllocHGlobal(8 * 5); //Alokacja pamięci na 5 wskaźników
            IntPtr[] arrayArray = new IntPtr[5];
            for (int i = 0; i < 5; i++)
            {
                arrayArray[i] = Marshal.AllocHGlobal(11); //Alokacja pamięci na 11 bajtów
                Marshal.WriteInt64(initArray + i*8, arrayArray[i].ToInt64());
            }

            Program.createPolybiusSquare(initArray, keywordArray);

            
            for (int i = 0; i < 5; i++)
            {
                Marshal.Copy(arrayArray[i], square[i], 0, 11);
                Marshal.FreeHGlobal(arrayArray[i]);
            }
            Marshal.FreeHGlobal(initArray);

            
            //encryptedTextAnswerRichTextBox.Text = Program.checkCharactersInKeyword(array).ToString();
        }
    }
}
