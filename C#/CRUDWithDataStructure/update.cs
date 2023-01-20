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
    public partial class update : Form
    {
        public update()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 f = new Form1();
            f.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Student student = new Student();
            student.rollNoupdate = Int32.Parse(textBox1.Text);
            student.nameupdate = textBox2.Text;
            student.fatherNameupdate = textBox3.Text;
            student.semesterupdate = textBox4.Text;

            if (radioButton1.Checked == true)
            {
                student.genderupdate = radioButton1.Text;
            }
            else
            {
                student.genderupdate = radioButton2.Text;
            }
            student.showupdate();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Student student = new Student();
            student.rollNoupdate = Int32.Parse(textBox1.Text);
            student.nameupdate = textBox2.Text;
            student.fatherNameupdate = textBox3.Text;
            student.semesterupdate = textBox4.Text;

            if (radioButton1.Checked == true)
            {
                student.genderupdate = radioButton1.Text;
            }
            else
            {
                student.genderupdate = radioButton2.Text;
            }
            student.editUpdate();
        }
    }
}
