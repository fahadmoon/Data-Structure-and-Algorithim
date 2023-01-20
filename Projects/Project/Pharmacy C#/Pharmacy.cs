using _1.Classes;
using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Text;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1
{
    public partial class Pharmacy : Form
    {
        private Button currentButton;
        public Random random;
        private int tempIndex;
        private Form activateForm;
        public Pharmacy()
        {
            InitializeComponent();
            random = new Random();
            this.Text = string.Empty;
            this.ControlBox = false;
            this.MaximizedBounds = Screen.FromHandle(this.Handle).WorkingArea;
            

        }

       

        [DllImport("user32.DLL", EntryPoint = "ReleaseCapture")]
        private extern static void ReleaseCapture();

        [DllImport("user32.DLL", EntryPoint = "SendMessage")]
        private extern static void SendMessage(System.IntPtr hWnd, int wMsg, int wParam, int lParam);
        private Color SelectColor()
        {
            int index = random.Next(ColorChange.ColorList.Count);
            while(tempIndex==index)
            {
                tempIndex++;
            }
            tempIndex = index;
            string color=ColorChange.ColorList[index];
            return ColorTranslator.FromHtml(color);
        }
        private void ActivateButton(object btnSender)
        {
            if (btnSender != null)
            {
                if (currentButton != btnSender)
                {
                    DisableButton();
                    Color color = SelectColor();
                    currentButton = (Button)btnSender;
                    currentButton.BackColor = color;
                    currentButton.ForeColor = Color.White;
                    currentButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                    panel3.BackColor = color;
                    panel2.BackColor = ColorChange.ChangeColorBrightness(color, -0.2);
                    ColorChange.PrimaryColor = color;
                    ColorChange.SecondryColor = ColorChange.ChangeColorBrightness(color, -0.2);
                }
            }
        }
        private void DisableButton()
        {
            foreach (Control prevBtn in panel1.Controls)
            {
                if (prevBtn.GetType() == typeof(Button))
                {
                    prevBtn.BackColor = Color.FromArgb(51, 51, 78);
                    prevBtn.ForeColor = Color.White;
                    prevBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));

                }
            }
        }
        private void OpenChildForm(Form childForm, object senderBtn)
        {
            if (activateForm != null)
            {
                activateForm.Close();

            }
            ActivateButton(senderBtn);
            activateForm = childForm;
            childForm.TopLevel = false;
            childForm.FormBorderStyle = FormBorderStyle.None;
            childForm.Dock = DockStyle.Fill;
            this.PanelActiviteForm.Controls.Add(childForm);
            this.PanelActiviteForm.Tag = childForm;
            childForm.BringToFront();
            childForm.Show();
            homeLabel.Text = childForm.Text;
            button10.Visible = true;
        }

        private void Pharmacy_Load(object sender, EventArgs e)
        {

        }

        public void hideSubMenu()
        {
            panelMediaSubMenu.Visible = false;
            panelCheck_Medicine.Visible = false;
            panelAdd_Stock.Visible = false;

        }

        private void showSubMenu(Panel subMenu, object sender)
        {
            if (subMenu.Visible == false)
            {
                ActivateButton(sender);
                hideSubMenu();
                subMenu.Visible = true;
            }
            else
                subMenu.Visible = false;
        }
        private void buttonproduct_Click(object sender, EventArgs e)
        {
            
            showSubMenu(panelMediaSubMenu, sender);
        }

        private void panel3_MouseDown(object sender, MouseEventArgs e)
        {
            ReleaseCapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }
      
        private void button7_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button8_Click(object sender, EventArgs e)
        {
        }

        private void button9_Click(object sender, EventArgs e)
        {
            
        }

        private void button7_Click_1(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button8_Click_1(object sender, EventArgs e)
        {

            if (WindowState == FormWindowState.Normal)
                this.WindowState = FormWindowState.Maximized;
            else
                this.WindowState = FormWindowState.Normal;
        }

        private void button9_Click_1(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void Reset()
        {
            DisableButton();
            homeLabel.Text = "HOME";
            panel3.BackColor = Color.FromArgb(0, 150, 136);
            panel2.BackColor = Color.FromArgb(39, 39, 58);
            currentButton = null;
            button10.Visible = false;
        }
        private void button10_Click(object sender, EventArgs e)
        {
            if (activateForm != null)
            {
                activateForm.Close();

            }
            Reset();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            OpenChildForm(new Forms.Add_Empolyees(), sender);
            hideSubMenu();

        }

        private void button12_Click(object sender, EventArgs e)
        {
            OpenChildForm(new Forms.UpdateEmployeeRecord(), sender);
            hideSubMenu();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            ActivateButton(sender);
            hideSubMenu();
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            showSubMenu(panelAdd_Stock, sender);
        }

        private void BtnCheckMedicine_Click(object sender, EventArgs e)
        {
            showSubMenu(panelCheck_Medicine, sender);
        }

        private void BtnCheckEmployee_Click(object sender, EventArgs e)
        {

        }
    }
}
