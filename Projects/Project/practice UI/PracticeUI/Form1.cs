using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PracticeUI
{
    public partial class Form1 : Form
    {
        private Button currentButton;
        private Random random;
        private int tempIndex;
        private Form activateForm;
        public Form1()
        {
            InitializeComponent();
            random = new Random();
        }
       
        private void button3_Click(object sender, EventArgs e)
        {
            OpenChildForm(new Forms.FormSearch(), sender);
        }
        //Method
        private Color SelectThemeColor()
        {
            int index=random.Next(ThemeColor.ColorList.Count);
            while(tempIndex==index)
            {
                index=random.Next(ThemeColor.ColorList.Count);
            }
            tempIndex = index;
            string color = ThemeColor.ColorList[index];
            return ColorTranslator.FromHtml(color);
        }
        private void ActivateButton(object btnSender)
        {
            if(btnSender!=null)
            {
                if(currentButton!=btnSender)
                {
                    DisableButton();
                    Color color = SelectThemeColor();
                    currentButton = (Button)btnSender;
                    currentButton.BackColor = color;
                    currentButton.ForeColor = Color.White;
                    currentButton.Font=new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                    panel3.BackColor = color;
                    panel2.BackColor = ThemeColor.ChangeColorBrightness(color, -0.3);
                    ThemeColor.PrimaryColor = color;
                    ThemeColor.SecondryColor= ThemeColor.ChangeColorBrightness(color, -0.3);
                }
            }
        }
        private void DisableButton()
        {
            foreach(Control prevBtn in panel1.Controls)
            {
                if(prevBtn.GetType()==typeof(Button))
                {
                    prevBtn.BackColor = Color.FromArgb(51, 51, 78);
                    prevBtn.ForeColor = Color.White;
                    prevBtn.Font= new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));

                }
            }
        }
        private void OpenChildForm(Form childForm,object senderBtn)
        {
            if(activateForm!=null)
            {
                activateForm.Close();

            }
            ActivateButton(senderBtn);
            activateForm = childForm;
            childForm.TopLevel = false;
            childForm.FormBorderStyle = FormBorderStyle.None;
            childForm.Dock = DockStyle.Fill;
            this.panelDesktop.Controls.Add(childForm);
            this.panelDesktop.Tag = childForm;
            childForm.BringToFront();
            childForm.Show();
            labelHome.Text = childForm.Text;
            buttonCloseChild.Visible = true;
        }

        private void buttonproduct_Click(object sender, EventArgs e)
        {
            OpenChildForm(new Forms.FormProduct(), sender);
        }

        private void buttonsell_Click(object sender, EventArgs e)
        {
           OpenChildForm(new Forms.FormSell(), sender);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            OpenChildForm(new Forms.FormUpdate(), sender);
        }

        private void buttonlogout_Click(object sender, EventArgs e)
        {
            OpenChildForm(new Forms.FormLogOut(), sender);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void buttonCloseChild_Click(object sender, EventArgs e)
        {
            if(activateForm!=null)
            {
                activateForm.Close();
                
            }
            Reset();
        }
        private void Reset()
        {
            DisableButton();
            labelHome.Text = "Home";
            panel3.BackColor = Color.FromArgb(0, 158, 136);
            panel2.BackColor = Color.FromArgb(66, 66, 88);
            currentButton = null;
            buttonCloseChild.Visible = false;
        }

        private void panelDesktop_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void buttonCloseChild_Click_1(object sender, EventArgs e)
        {

        }
    }


}
