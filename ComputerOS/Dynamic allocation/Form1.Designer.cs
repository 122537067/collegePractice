namespace Dynamic_allocation
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.button_add = new System.Windows.Forms.Button();
            this.groupBox = new System.Windows.Forms.GroupBox();
            this.label_name = new System.Windows.Forms.Label();
            this.label_size = new System.Windows.Forms.Label();
            this.textBox_check = new System.Windows.Forms.TextBox();
            this.button_random = new System.Windows.Forms.Button();
            this.button_submit = new System.Windows.Forms.Button();
            this.panel_draw = new System.Windows.Forms.Panel();
            this.groupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // button_add
            // 
            this.button_add.Location = new System.Drawing.Point(12, 12);
            this.button_add.Name = "button_add";
            this.button_add.Size = new System.Drawing.Size(75, 23);
            this.button_add.TabIndex = 4;
            this.button_add.Text = "增加进程";
            this.button_add.UseVisualStyleBackColor = true;
            this.button_add.Click += new System.EventHandler(this.button_add_Click);
            // 
            // groupBox
            // 
            this.groupBox.Controls.Add(this.label_name);
            this.groupBox.Controls.Add(this.label_size);
            this.groupBox.Location = new System.Drawing.Point(12, 50);
            this.groupBox.Name = "groupBox";
            this.groupBox.Size = new System.Drawing.Size(350, 462);
            this.groupBox.TabIndex = 5;
            this.groupBox.TabStop = false;
            this.groupBox.Text = "进程";
            // 
            // label_name
            // 
            this.label_name.AutoSize = true;
            this.label_name.Location = new System.Drawing.Point(44, 34);
            this.label_name.Name = "label_name";
            this.label_name.Size = new System.Drawing.Size(41, 12);
            this.label_name.TabIndex = 4;
            this.label_name.Text = "进程名";
            // 
            // label_size
            // 
            this.label_size.AutoSize = true;
            this.label_size.Location = new System.Drawing.Point(177, 34);
            this.label_size.Name = "label_size";
            this.label_size.Size = new System.Drawing.Size(89, 12);
            this.label_size.TabIndex = 5;
            this.label_size.Text = "空间大小（KB）";
            // 
            // textBox_check
            // 
            this.textBox_check.Location = new System.Drawing.Point(403, 62);
            this.textBox_check.Multiline = true;
            this.textBox_check.Name = "textBox_check";
            this.textBox_check.Size = new System.Drawing.Size(187, 450);
            this.textBox_check.TabIndex = 6;
            // 
            // button_random
            // 
            this.button_random.Location = new System.Drawing.Point(106, 12);
            this.button_random.Name = "button_random";
            this.button_random.Size = new System.Drawing.Size(93, 23);
            this.button_random.TabIndex = 7;
            this.button_random.Text = "生成随机顺序";
            this.button_random.UseVisualStyleBackColor = true;
            this.button_random.Click += new System.EventHandler(this.button_random_Click);
            // 
            // button_submit
            // 
            this.button_submit.Location = new System.Drawing.Point(515, 33);
            this.button_submit.Name = "button_submit";
            this.button_submit.Size = new System.Drawing.Size(75, 23);
            this.button_submit.TabIndex = 8;
            this.button_submit.Text = "完成";
            this.button_submit.UseVisualStyleBackColor = true;
            this.button_submit.Click += new System.EventHandler(this.button_submit_Click);
            // 
            // panel_draw
            // 
            this.panel_draw.Location = new System.Drawing.Point(611, 12);
            this.panel_draw.Name = "panel_draw";
            this.panel_draw.Size = new System.Drawing.Size(475, 500);
            this.panel_draw.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1110, 522);
            this.Controls.Add(this.panel_draw);
            this.Controls.Add(this.button_submit);
            this.Controls.Add(this.button_random);
            this.Controls.Add(this.textBox_check);
            this.Controls.Add(this.groupBox);
            this.Controls.Add(this.button_add);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox.ResumeLayout(false);
            this.groupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button button_add;
        private System.Windows.Forms.GroupBox groupBox;
        private System.Windows.Forms.Label label_name;
        private System.Windows.Forms.Label label_size;
        private System.Windows.Forms.TextBox textBox_check;
        private System.Windows.Forms.Button button_random;
        private System.Windows.Forms.Button button_submit;
        private System.Windows.Forms.Panel panel_draw;
    }
}

