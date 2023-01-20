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
    public partial class delete : Form
    {
        public delete()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 f = new Form1();
            f.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Student student = new Student();
            student.rollNodelete = Int32.Parse(textBox1.Text);
           student.check= checkBox1.Checked;
            student.deleteRecord();
        }
    }
}
