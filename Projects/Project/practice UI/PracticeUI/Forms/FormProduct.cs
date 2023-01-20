using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PracticeUI.Forms
{
    public partial class FormProduct : Form
    {
        public FormProduct()
        {
            InitializeComponent();
        }

        private void FormProduct_Load(object sender, EventArgs e)
        {
            LoadTheme();
        }

        private void LoadTheme()
        {
            foreach(Control b in this.Controls)
            {
                if (b.GetType() == typeof(Button))
                {
                    Button btn = (Button)b;
                    btn.BackColor = ThemeColor.PrimaryColor;
                    btn.ForeColor = Color.White;
                    btn.FlatAppearance.BorderColor = ThemeColor.SecondryColor;
                }
            }
            label1.ForeColor = ThemeColor.SecondryColor;
            label5.ForeColor = ThemeColor.PrimaryColor;
        }
    }
}
