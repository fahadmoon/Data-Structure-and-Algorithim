﻿using System;
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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            AddRecord addRecord = new AddRecord();
            addRecord.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            ShowData show = new ShowData();
            show.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Hide();
            update update = new update();
            update.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Hide();
            delete delete = new delete();
            delete.Show();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
