using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CRUDWithDataStructure
{
    public partial class AddRecord : Form
    {
        
        public AddRecord()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Student student = new Student();
             student.rollNo = Int32.Parse(textBox1.Text);
            student.name = textBox2.Text;
            student.fatherName = textBox3.Text;
            student.semester = textBox4.Text;
            
            if(radioButton1.Checked==true)
            {
                student.gender = radioButton1.Text;
            }
            else
            {
                student.gender = radioButton2.Text;
            }

            student.AddRecord();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 f = new Form1();
            f.Show();
        }
    }
}
