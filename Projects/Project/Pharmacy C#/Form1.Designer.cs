namespace _1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.bunifuCircleProgress1 = new Bunifu.UI.WinForms.BunifuCircleProgress();
            this.label2 = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // bunifuCircleProgress1
            // 
            this.bunifuCircleProgress1.Animated = false;
            this.bunifuCircleProgress1.AnimationInterval = 1;
            this.bunifuCircleProgress1.AnimationSpeed = 1;
            this.bunifuCircleProgress1.BackColor = System.Drawing.Color.Transparent;
            this.bunifuCircleProgress1.CircleMargin = 10;
            this.bunifuCircleProgress1.Font = new System.Drawing.Font("Microsoft Sans Serif", 40F, System.Drawing.FontStyle.Bold);
            this.bunifuCircleProgress1.ForeColor = System.Drawing.Color.White;
            this.bunifuCircleProgress1.IsPercentage = false;
            this.bunifuCircleProgress1.LineProgressThickness = 10;
            this.bunifuCircleProgress1.LineThickness = 10;
            this.bunifuCircleProgress1.Location = new System.Drawing.Point(222, 120);
            this.bunifuCircleProgress1.Name = "bunifuCircleProgress1";
            this.bunifuCircleProgress1.ProgressAnimationSpeed = 5;
            this.bunifuCircleProgress1.ProgressBackColor = System.Drawing.Color.White;
            this.bunifuCircleProgress1.ProgressColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.bunifuCircleProgress1.ProgressColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.bunifuCircleProgress1.ProgressEndCap = Bunifu.UI.WinForms.BunifuCircleProgress.CapStyles.Round;
            this.bunifuCircleProgress1.ProgressFillStyle = Bunifu.UI.WinForms.BunifuCircleProgress.FillStyles.Solid;
            this.bunifuCircleProgress1.ProgressStartCap = Bunifu.UI.WinForms.BunifuCircleProgress.CapStyles.Round;
            this.bunifuCircleProgress1.SecondaryFont = new System.Drawing.Font("Microsoft Sans Serif", 16F);
            this.bunifuCircleProgress1.Size = new System.Drawing.Size(184, 184);
            this.bunifuCircleProgress1.SubScriptColor = System.Drawing.Color.White;
            this.bunifuCircleProgress1.SubScriptMargin = new System.Windows.Forms.Padding(5, -20, 0, 0);
            this.bunifuCircleProgress1.SubScriptText = "%";
            this.bunifuCircleProgress1.SuperScriptColor = System.Drawing.Color.White;
            this.bunifuCircleProgress1.SuperScriptMargin = new System.Windows.Forms.Padding(5, 20, 0, 0);
            this.bunifuCircleProgress1.SuperScriptText = "";
            this.bunifuCircleProgress1.TabIndex = 10;
            this.bunifuCircleProgress1.Tag = "";
            this.bunifuCircleProgress1.Text = "30";
            this.bunifuCircleProgress1.TextMargin = new System.Windows.Forms.Padding(0, 5, 0, 0);
            this.bunifuCircleProgress1.Value = 30;
            this.bunifuCircleProgress1.ValueByTransition = 30;
            this.bunifuCircleProgress1.ValueMargin = new System.Windows.Forms.Padding(0, 5, 0, 0);
            this.bunifuCircleProgress1.ProgressChanged += new System.EventHandler<Bunifu.UI.WinForms.BunifuCircleProgress.ProgressChangedEventArgs>(this.bunifuCircleProgress1_ProgressChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Nirmala UI", 18F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))));
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.label2.Location = new System.Drawing.Point(129, 47);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(458, 41);
            this.label2.TabIndex = 20;
            this.label2.Text = "Pharmacy Management System";
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // button1
            // 
            this.button1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button1.BackgroundImage")));
            this.button1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button1.FlatAppearance.BorderSize = 0;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.button1.Location = new System.Drawing.Point(19, 28);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(94, 94);
            this.button1.TabIndex = 21;
            this.button1.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Green;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(629, 335);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.bunifuCircleProgress1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form1";
            this.Padding = new System.Windows.Forms.Padding(2);
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.TransparencyKey = System.Drawing.Color.Black;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Bunifu.UI.WinForms.BunifuCircleProgress bunifuCircleProgress1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button button1;
    }
}

