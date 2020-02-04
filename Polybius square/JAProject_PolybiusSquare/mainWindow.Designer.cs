namespace JAProject_PolybiusSquare
{
    partial class mainWindow
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
            this.encryptButton = new System.Windows.Forms.Button();
            this.textLabel = new System.Windows.Forms.Label();
            this.cppRadioButton = new System.Windows.Forms.RadioButton();
            this.asmRadioButton = new System.Windows.Forms.RadioButton();
            this.keywordTextBox = new System.Windows.Forms.TextBox();
            this.keywordLabel = new System.Windows.Forms.Label();
            this.textRichTextBox = new System.Windows.Forms.RichTextBox();
            this.threadNumericUpDown = new System.Windows.Forms.NumericUpDown();
            this.dlltypeLabel = new System.Windows.Forms.Label();
            this.threadsLabel = new System.Windows.Forms.Label();
            this.encryptedTextLabel = new System.Windows.Forms.Label();
            this.conversionTimeLabel = new System.Windows.Forms.Label();
            this.encryptedTextAnswerRichTextBox = new System.Windows.Forms.RichTextBox();
            this.conversionTimeAnswerLabel = new System.Windows.Forms.Label();
            this.keywordErrorLabel = new System.Windows.Forms.Label();
            this.textErrorLabel = new System.Windows.Forms.Label();
            this.threadErrorLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.threadNumericUpDown)).BeginInit();
            this.SuspendLayout();
            // 
            // encryptButton
            // 
            this.encryptButton.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.encryptButton.BackColor = System.Drawing.SystemColors.InactiveCaption;
            this.encryptButton.Location = new System.Drawing.Point(303, 13);
            this.encryptButton.Name = "encryptButton";
            this.encryptButton.Size = new System.Drawing.Size(64, 391);
            this.encryptButton.TabIndex = 0;
            this.encryptButton.Text = "Encrypt";
            this.encryptButton.UseVisualStyleBackColor = false;
            this.encryptButton.Click += new System.EventHandler(this.encryptButton_Click);
            // 
            // textLabel
            // 
            this.textLabel.AutoSize = true;
            this.textLabel.Location = new System.Drawing.Point(12, 85);
            this.textLabel.Name = "textLabel";
            this.textLabel.Size = new System.Drawing.Size(81, 13);
            this.textLabel.TabIndex = 2;
            this.textLabel.Text = "Text to encrypt:";
            // 
            // cppRadioButton
            // 
            this.cppRadioButton.AutoSize = true;
            this.cppRadioButton.Checked = true;
            this.cppRadioButton.Location = new System.Drawing.Point(15, 321);
            this.cppRadioButton.Name = "cppRadioButton";
            this.cppRadioButton.Size = new System.Drawing.Size(44, 17);
            this.cppRadioButton.TabIndex = 4;
            this.cppRadioButton.TabStop = true;
            this.cppRadioButton.Text = "C++";
            this.cppRadioButton.UseVisualStyleBackColor = true;
            // 
            // asmRadioButton
            // 
            this.asmRadioButton.AutoSize = true;
            this.asmRadioButton.Location = new System.Drawing.Point(15, 344);
            this.asmRadioButton.Name = "asmRadioButton";
            this.asmRadioButton.Size = new System.Drawing.Size(48, 17);
            this.asmRadioButton.TabIndex = 5;
            this.asmRadioButton.Text = "ASM";
            this.asmRadioButton.UseVisualStyleBackColor = true;
            // 
            // keywordTextBox
            // 
            this.keywordTextBox.Location = new System.Drawing.Point(125, 13);
            this.keywordTextBox.Name = "keywordTextBox";
            this.keywordTextBox.Size = new System.Drawing.Size(140, 20);
            this.keywordTextBox.TabIndex = 8;
            // 
            // keywordLabel
            // 
            this.keywordLabel.AutoSize = true;
            this.keywordLabel.Location = new System.Drawing.Point(42, 16);
            this.keywordLabel.Name = "keywordLabel";
            this.keywordLabel.Size = new System.Drawing.Size(51, 13);
            this.keywordLabel.TabIndex = 9;
            this.keywordLabel.Text = "Keyword:";
            // 
            // textRichTextBox
            // 
            this.textRichTextBox.Location = new System.Drawing.Point(125, 85);
            this.textRichTextBox.Name = "textRichTextBox";
            this.textRichTextBox.Size = new System.Drawing.Size(140, 150);
            this.textRichTextBox.TabIndex = 10;
            this.textRichTextBox.Text = "";
            // 
            // threadNumericUpDown
            // 
            this.threadNumericUpDown.Location = new System.Drawing.Point(125, 321);
            this.threadNumericUpDown.Maximum = new decimal(new int[] {
            64,
            0,
            0,
            0});
            this.threadNumericUpDown.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.threadNumericUpDown.Name = "threadNumericUpDown";
            this.threadNumericUpDown.Size = new System.Drawing.Size(140, 20);
            this.threadNumericUpDown.TabIndex = 11;
            this.threadNumericUpDown.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // dlltypeLabel
            // 
            this.dlltypeLabel.AutoSize = true;
            this.dlltypeLabel.Location = new System.Drawing.Point(12, 305);
            this.dlltypeLabel.Name = "dlltypeLabel";
            this.dlltypeLabel.Size = new System.Drawing.Size(53, 13);
            this.dlltypeLabel.TabIndex = 12;
            this.dlltypeLabel.Text = "DLL type:";
            // 
            // threadsLabel
            // 
            this.threadsLabel.AutoSize = true;
            this.threadsLabel.Location = new System.Drawing.Point(122, 305);
            this.threadsLabel.Name = "threadsLabel";
            this.threadsLabel.Size = new System.Drawing.Size(97, 13);
            this.threadsLabel.TabIndex = 13;
            this.threadsLabel.Text = "Number of threads:";
            // 
            // encryptedTextLabel
            // 
            this.encryptedTextLabel.AutoSize = true;
            this.encryptedTextLabel.Location = new System.Drawing.Point(388, 16);
            this.encryptedTextLabel.Name = "encryptedTextLabel";
            this.encryptedTextLabel.Size = new System.Drawing.Size(78, 13);
            this.encryptedTextLabel.TabIndex = 14;
            this.encryptedTextLabel.Text = "Encrypted text:";
            this.encryptedTextLabel.Click += new System.EventHandler(this.encryptedTextLabel_Click);
            // 
            // conversionTimeLabel
            // 
            this.conversionTimeLabel.AutoSize = true;
            this.conversionTimeLabel.Location = new System.Drawing.Point(388, 222);
            this.conversionTimeLabel.Name = "conversionTimeLabel";
            this.conversionTimeLabel.Size = new System.Drawing.Size(107, 13);
            this.conversionTimeLabel.TabIndex = 16;
            this.conversionTimeLabel.Text = "Conversion time [ms]:";
            // 
            // encryptedTextAnswerRichTextBox
            // 
            this.encryptedTextAnswerRichTextBox.Location = new System.Drawing.Point(503, 16);
            this.encryptedTextAnswerRichTextBox.Name = "encryptedTextAnswerRichTextBox";
            this.encryptedTextAnswerRichTextBox.ReadOnly = true;
            this.encryptedTextAnswerRichTextBox.Size = new System.Drawing.Size(140, 150);
            this.encryptedTextAnswerRichTextBox.TabIndex = 22;
            this.encryptedTextAnswerRichTextBox.Text = "";
            // 
            // conversionTimeAnswerLabel
            // 
            this.conversionTimeAnswerLabel.AutoSize = true;
            this.conversionTimeAnswerLabel.Location = new System.Drawing.Point(501, 222);
            this.conversionTimeAnswerLabel.Name = "conversionTimeAnswerLabel";
            this.conversionTimeAnswerLabel.Size = new System.Drawing.Size(0, 13);
            this.conversionTimeAnswerLabel.TabIndex = 23;
            // 
            // keywordErrorLabel
            // 
            this.keywordErrorLabel.AutoSize = true;
            this.keywordErrorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.keywordErrorLabel.ForeColor = System.Drawing.Color.Red;
            this.keywordErrorLabel.Location = new System.Drawing.Point(12, 38);
            this.keywordErrorLabel.Name = "keywordErrorLabel";
            this.keywordErrorLabel.Size = new System.Drawing.Size(0, 13);
            this.keywordErrorLabel.TabIndex = 25;
            // 
            // textErrorLabel
            // 
            this.textErrorLabel.AutoSize = true;
            this.textErrorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.textErrorLabel.ForeColor = System.Drawing.Color.Red;
            this.textErrorLabel.Location = new System.Drawing.Point(12, 240);
            this.textErrorLabel.Name = "textErrorLabel";
            this.textErrorLabel.Size = new System.Drawing.Size(0, 13);
            this.textErrorLabel.TabIndex = 27;
            // 
            // threadErrorLabel
            // 
            this.threadErrorLabel.AutoSize = true;
            this.threadErrorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.threadErrorLabel.ForeColor = System.Drawing.Color.Red;
            this.threadErrorLabel.Location = new System.Drawing.Point(125, 348);
            this.threadErrorLabel.Name = "threadErrorLabel";
            this.threadErrorLabel.Size = new System.Drawing.Size(0, 13);
            this.threadErrorLabel.TabIndex = 28;
            // 
            // mainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(665, 416);
            this.Controls.Add(this.threadErrorLabel);
            this.Controls.Add(this.textErrorLabel);
            this.Controls.Add(this.keywordErrorLabel);
            this.Controls.Add(this.conversionTimeAnswerLabel);
            this.Controls.Add(this.encryptedTextAnswerRichTextBox);
            this.Controls.Add(this.conversionTimeLabel);
            this.Controls.Add(this.encryptedTextLabel);
            this.Controls.Add(this.threadsLabel);
            this.Controls.Add(this.dlltypeLabel);
            this.Controls.Add(this.threadNumericUpDown);
            this.Controls.Add(this.textRichTextBox);
            this.Controls.Add(this.keywordLabel);
            this.Controls.Add(this.keywordTextBox);
            this.Controls.Add(this.asmRadioButton);
            this.Controls.Add(this.cppRadioButton);
            this.Controls.Add(this.textLabel);
            this.Controls.Add(this.encryptButton);
            this.Name = "mainWindow";
            this.Text = "Polybius Square";
            ((System.ComponentModel.ISupportInitialize)(this.threadNumericUpDown)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button encryptButton;
        private System.Windows.Forms.Label textLabel;
        private System.Windows.Forms.RadioButton cppRadioButton;
        private System.Windows.Forms.RadioButton asmRadioButton;
        private System.Windows.Forms.TextBox keywordTextBox;
        private System.Windows.Forms.Label keywordLabel;
        private System.Windows.Forms.RichTextBox textRichTextBox;
        private System.Windows.Forms.NumericUpDown threadNumericUpDown;
        private System.Windows.Forms.Label dlltypeLabel;
        private System.Windows.Forms.Label threadsLabel;
        private System.Windows.Forms.Label encryptedTextLabel;
        private System.Windows.Forms.Label conversionTimeLabel;
        private System.Windows.Forms.RichTextBox encryptedTextAnswerRichTextBox;
        private System.Windows.Forms.Label conversionTimeAnswerLabel;
        private System.Windows.Forms.Label keywordErrorLabel;
        private System.Windows.Forms.Label textErrorLabel;
        private System.Windows.Forms.Label threadErrorLabel;
    }
}

