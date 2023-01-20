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
    public partial class ShowData : Form
    {
        public ShowData()
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
            student.ShowRecord(Convert.ToInt32(textBox1.Text), label2.Text, label3.Text, label4.Text, label5.Text);

        }
    }
}
