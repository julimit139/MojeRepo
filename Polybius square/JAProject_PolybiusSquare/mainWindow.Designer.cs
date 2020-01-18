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
            ((System.ComponentModel.ISupportInitialize)(this.threadNumericUpDown)).BeginInit();
            this.SuspendLayout();
            // 
            // encryptButton
            // 
            this.encryptButton.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.encryptButton.BackColor = System.Drawing.SystemColors.InactiveCaption;
            this.encryptButton.Location = new System.Drawing.Point(303, 13);
            this.encryptButton.Name = "encryptButton";
            this.encryptButton.Size = new System.Drawing.Size(64, 319);
            this.encryptButton.TabIndex = 0;
            this.encryptButton.Text = "Encrypt";
            this.encryptButton.UseVisualStyleBackColor = false;
            this.encryptButton.Click += new System.EventHandler(this.encryptButton_Click);
            // 
            // textLabel
            // 
            this.textLabel.AutoSize = true;
            this.textLabel.Location = new System.Drawing.Point(12, 67);
            this.textLabel.Name = "textLabel";
            this.textLabel.Size = new System.Drawing.Size(81, 13);
            this.textLabel.TabIndex = 2;
            this.textLabel.Text = "Text to encrypt:";
            // 
            // cppRadioButton
            // 
            this.cppRadioButton.AutoSize = true;
            this.cppRadioButton.Location = new System.Drawing.Point(15, 275);
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
            this.asmRadioButton.Location = new System.Drawing.Point(15, 298);
            this.asmRadioButton.Name = "asmRadioButton";
            this.asmRadioButton.Size = new System.Drawing.Size(48, 17);
            this.asmRadioButton.TabIndex = 5;
            this.asmRadioButton.TabStop = true;
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
            //this.keywordLabel.Click += new System.EventHandler(this.label1_Click);
            // 
            // textRichTextBox
            // 
            this.textRichTextBox.Location = new System.Drawing.Point(125, 64);
            this.textRichTextBox.Name = "textRichTextBox";
            this.textRichTextBox.Size = new System.Drawing.Size(140, 150);
            this.textRichTextBox.TabIndex = 10;
            this.textRichTextBox.Text = "";
            // 
            // threadNumericUpDown
            // 
            this.threadNumericUpDown.Location = new System.Drawing.Point(125, 275);
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
            this.threadNumericUpDown.Size = new System.Drawing.Size(120, 20);
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
            this.dlltypeLabel.Location = new System.Drawing.Point(12, 250);
            this.dlltypeLabel.Name = "dlltypeLabel";
            this.dlltypeLabel.Size = new System.Drawing.Size(53, 13);
            this.dlltypeLabel.TabIndex = 12;
            this.dlltypeLabel.Text = "DLL type:";
            // 
            // threadsLabel
            // 
            this.threadsLabel.AutoSize = true;
            this.threadsLabel.Location = new System.Drawing.Point(122, 250);
            this.threadsLabel.Name = "threadsLabel";
            this.threadsLabel.Size = new System.Drawing.Size(97, 13);
            this.threadsLabel.TabIndex = 13;
            this.threadsLabel.Text = "Number of threads:";
            //this.threadsLabel.Click += new System.EventHandler(this.threadsLabel_Click);
            // 
            // encryptedTextLabel
            // 
            this.encryptedTextLabel.AutoSize = true;
            this.encryptedTextLabel.Location = new System.Drawing.Point(399, 67);
            this.encryptedTextLabel.Name = "encryptedTextLabel";
            this.encryptedTextLabel.Size = new System.Drawing.Size(78, 13);
            this.encryptedTextLabel.TabIndex = 14;
            this.encryptedTextLabel.Text = "Encrypted text:";
            // 
            // conversionTimeLabel
            // 
            this.conversionTimeLabel.AutoSize = true;
            this.conversionTimeLabel.Location = new System.Drawing.Point(399, 250);
            this.conversionTimeLabel.Name = "conversionTimeLabel";
            this.conversionTimeLabel.Size = new System.Drawing.Size(85, 13);
            this.conversionTimeLabel.TabIndex = 16;
            this.conversionTimeLabel.Text = "Conversion time:";
            // 
            // encryptedTextAnswerRichTextBox
            // 
            this.encryptedTextAnswerRichTextBox.Location = new System.Drawing.Point(500, 64);
            this.encryptedTextAnswerRichTextBox.Name = "encryptedTextAnswerRichTextBox";
            this.encryptedTextAnswerRichTextBox.ReadOnly = true;
            this.encryptedTextAnswerRichTextBox.Size = new System.Drawing.Size(140, 150);
            this.encryptedTextAnswerRichTextBox.TabIndex = 22;
            this.encryptedTextAnswerRichTextBox.Text = "";
            // 
            // conversionTimeAnswerLabel
            // 
            this.conversionTimeAnswerLabel.AutoSize = true;
            this.conversionTimeAnswerLabel.Location = new System.Drawing.Point(500, 250);
            this.conversionTimeAnswerLabel.Name = "conversionTimeAnswerLabel";
            this.conversionTimeAnswerLabel.Size = new System.Drawing.Size(0, 13);
            this.conversionTimeAnswerLabel.TabIndex = 23;
            // 
            // mainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(665, 344);
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
    }
}

