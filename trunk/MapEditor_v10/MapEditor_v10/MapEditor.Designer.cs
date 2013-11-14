namespace MapEditor_v10
{
    partial class MapEditor
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MapEditor));
            this.menuGame = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveTreeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.imageList = new System.Windows.Forms.ImageList(this.components);
            this.PnContain = new System.Windows.Forms.Panel();
            this.ptbContain = new System.Windows.Forms.PictureBox();
            this.TabBackGround = new System.Windows.Forms.TabControl();
            this.BackGround = new System.Windows.Forms.TabPage();
            this.btnHouse = new System.Windows.Forms.Button();
            this.btnFence = new System.Windows.Forms.Button();
            this.btnMediumPipe = new System.Windows.Forms.Button();
            this.btnSmalltree = new System.Windows.Forms.Button();
            this.btnMountain = new System.Windows.Forms.Button();
            this.btnSmallPipe = new System.Windows.Forms.Button();
            this.btnBigtree = new System.Windows.Forms.Button();
            this.btnBigpipe = new System.Windows.Forms.Button();
            this.btnGrass = new System.Windows.Forms.Button();
            this.btnCloud = new System.Windows.Forms.Button();
            this.ObjectGame = new System.Windows.Forms.TabPage();
            this.button10 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.DrawRect = new System.Windows.Forms.Button();
            this.menuGame.SuspendLayout();
            this.PnContain.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ptbContain)).BeginInit();
            this.TabBackGround.SuspendLayout();
            this.BackGround.SuspendLayout();
            this.ObjectGame.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuGame
            // 
            this.menuGame.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuGame.Location = new System.Drawing.Point(0, 0);
            this.menuGame.Name = "menuGame";
            this.menuGame.Size = new System.Drawing.Size(970, 24);
            this.menuGame.TabIndex = 3;
            this.menuGame.Text = "menuGame";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.loadToolStripMenuItem,
            this.saveTreeToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.Size = new System.Drawing.Size(121, 22);
            this.newToolStripMenuItem.Text = "New";
            this.newToolStripMenuItem.Click += new System.EventHandler(this.newToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(121, 22);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // loadToolStripMenuItem
            // 
            this.loadToolStripMenuItem.Name = "loadToolStripMenuItem";
            this.loadToolStripMenuItem.Size = new System.Drawing.Size(121, 22);
            this.loadToolStripMenuItem.Text = "Load";
            this.loadToolStripMenuItem.Click += new System.EventHandler(this.loadToolStripMenuItem_Click);
            // 
            // saveTreeToolStripMenuItem
            // 
            this.saveTreeToolStripMenuItem.Name = "saveTreeToolStripMenuItem";
            this.saveTreeToolStripMenuItem.Size = new System.Drawing.Size(121, 22);
            this.saveTreeToolStripMenuItem.Text = "SaveTree";
            // 
            // imageList
            // 
            this.imageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList.ImageStream")));
            this.imageList.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList.Images.SetKeyName(0, "cloud.png");
            this.imageList.Images.SetKeyName(1, "cloud.png");
            this.imageList.Images.SetKeyName(2, "grass.png");
            this.imageList.Images.SetKeyName(3, "big_tree.png");
            this.imageList.Images.SetKeyName(4, "fence.png");
            this.imageList.Images.SetKeyName(5, "moutain.png");
            this.imageList.Images.SetKeyName(6, "house.png");
            this.imageList.Images.SetKeyName(7, "brick.png");
            this.imageList.Images.SetKeyName(8, "brick2.png");
            this.imageList.Images.SetKeyName(9, "flower_01.jpg");
            this.imageList.Images.SetKeyName(10, "item_01.png");
            this.imageList.Images.SetKeyName(11, "item_02.png");
            this.imageList.Images.SetKeyName(12, "item_04.png");
            this.imageList.Images.SetKeyName(13, "item_07.png");
            this.imageList.Images.SetKeyName(14, "CoinQuestion.png");
            this.imageList.Images.SetKeyName(15, "mushroom.png");
            this.imageList.Images.SetKeyName(16, "turtle.png");
            this.imageList.Images.SetKeyName(17, "small_pipe.png");
            this.imageList.Images.SetKeyName(18, "big_pipe.png");
            // 
            // PnContain
            // 
            this.PnContain.AutoScroll = true;
            this.PnContain.Controls.Add(this.ptbContain);
            this.PnContain.Location = new System.Drawing.Point(210, 83);
            this.PnContain.Name = "PnContain";
            this.PnContain.Size = new System.Drawing.Size(748, 400);
            this.PnContain.TabIndex = 4;
            // 
            // ptbContain
            // 
            this.ptbContain.BackColor = System.Drawing.SystemColors.Highlight;
            this.ptbContain.Location = new System.Drawing.Point(3, 0);
            this.ptbContain.Name = "ptbContain";
            this.ptbContain.Size = new System.Drawing.Size(15000, 2000);
            this.ptbContain.TabIndex = 0;
            this.ptbContain.TabStop = false;
            this.ptbContain.Click += new System.EventHandler(this.ptbContain_Click);
            this.ptbContain.Paint += new System.Windows.Forms.PaintEventHandler(this.ptbContain_Paint);
            this.ptbContain.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ptbContain_MouseDown);
            this.ptbContain.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ptbContain_MouseMove);
            this.ptbContain.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ptbContain_MouseUp);
            // 
            // TabBackGround
            // 
            this.TabBackGround.Controls.Add(this.BackGround);
            this.TabBackGround.Controls.Add(this.ObjectGame);
            this.TabBackGround.Location = new System.Drawing.Point(0, 27);
            this.TabBackGround.Name = "TabBackGround";
            this.TabBackGround.SelectedIndex = 0;
            this.TabBackGround.Size = new System.Drawing.Size(200, 456);
            this.TabBackGround.TabIndex = 6;
            this.TabBackGround.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TabBackGround_KeyDown);
            // 
            // BackGround
            // 
            this.BackGround.BackColor = System.Drawing.Color.Silver;
            this.BackGround.Controls.Add(this.btnHouse);
            this.BackGround.Controls.Add(this.btnFence);
            this.BackGround.Controls.Add(this.btnMediumPipe);
            this.BackGround.Controls.Add(this.btnSmalltree);
            this.BackGround.Controls.Add(this.btnMountain);
            this.BackGround.Controls.Add(this.btnSmallPipe);
            this.BackGround.Controls.Add(this.btnBigtree);
            this.BackGround.Controls.Add(this.btnBigpipe);
            this.BackGround.Controls.Add(this.btnGrass);
            this.BackGround.Controls.Add(this.btnCloud);
            this.BackGround.Location = new System.Drawing.Point(4, 22);
            this.BackGround.Name = "BackGround";
            this.BackGround.Padding = new System.Windows.Forms.Padding(3);
            this.BackGround.Size = new System.Drawing.Size(192, 430);
            this.BackGround.TabIndex = 0;
            this.BackGround.Text = "BackGround";
            // 
            // btnHouse
            // 
            this.btnHouse.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnHouse.BackgroundImage")));
            this.btnHouse.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnHouse.Location = new System.Drawing.Point(108, 349);
            this.btnHouse.Name = "btnHouse";
            this.btnHouse.Size = new System.Drawing.Size(60, 60);
            this.btnHouse.TabIndex = 9;
            this.btnHouse.UseVisualStyleBackColor = true;
            this.btnHouse.Click += new System.EventHandler(this.btnHouse_Click);
            // 
            // btnFence
            // 
            this.btnFence.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnFence.BackgroundImage")));
            this.btnFence.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnFence.Location = new System.Drawing.Point(108, 266);
            this.btnFence.Name = "btnFence";
            this.btnFence.Size = new System.Drawing.Size(60, 60);
            this.btnFence.TabIndex = 8;
            this.btnFence.UseVisualStyleBackColor = true;
            this.btnFence.Click += new System.EventHandler(this.btnFence_Click);
            // 
            // btnMediumPipe
            // 
            this.btnMediumPipe.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnMediumPipe.BackgroundImage")));
            this.btnMediumPipe.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnMediumPipe.Location = new System.Drawing.Point(108, 184);
            this.btnMediumPipe.Name = "btnMediumPipe";
            this.btnMediumPipe.Size = new System.Drawing.Size(60, 60);
            this.btnMediumPipe.TabIndex = 7;
            this.btnMediumPipe.UseVisualStyleBackColor = true;
            this.btnMediumPipe.Click += new System.EventHandler(this.btnMediumPipe_Click);
            // 
            // btnSmalltree
            // 
            this.btnSmalltree.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnSmalltree.BackgroundImage")));
            this.btnSmalltree.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnSmalltree.Location = new System.Drawing.Point(108, 100);
            this.btnSmalltree.Name = "btnSmalltree";
            this.btnSmalltree.Size = new System.Drawing.Size(60, 60);
            this.btnSmalltree.TabIndex = 6;
            this.btnSmalltree.UseVisualStyleBackColor = true;
            this.btnSmalltree.Click += new System.EventHandler(this.btnSmalltree_Click);
            // 
            // btnMountain
            // 
            this.btnMountain.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnMountain.BackgroundImage")));
            this.btnMountain.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnMountain.Location = new System.Drawing.Point(21, 349);
            this.btnMountain.Name = "btnMountain";
            this.btnMountain.Size = new System.Drawing.Size(60, 60);
            this.btnMountain.TabIndex = 5;
            this.btnMountain.UseVisualStyleBackColor = true;
            this.btnMountain.Click += new System.EventHandler(this.btnMountain_Click);
            // 
            // btnSmallPipe
            // 
            this.btnSmallPipe.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnSmallPipe.BackgroundImage")));
            this.btnSmallPipe.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnSmallPipe.Location = new System.Drawing.Point(21, 266);
            this.btnSmallPipe.Name = "btnSmallPipe";
            this.btnSmallPipe.Size = new System.Drawing.Size(60, 60);
            this.btnSmallPipe.TabIndex = 4;
            this.btnSmallPipe.UseVisualStyleBackColor = true;
            this.btnSmallPipe.Click += new System.EventHandler(this.btnSmallPipe_Click);
            // 
            // btnBigtree
            // 
            this.btnBigtree.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnBigtree.BackgroundImage")));
            this.btnBigtree.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnBigtree.Location = new System.Drawing.Point(21, 100);
            this.btnBigtree.Name = "btnBigtree";
            this.btnBigtree.Size = new System.Drawing.Size(60, 60);
            this.btnBigtree.TabIndex = 3;
            this.btnBigtree.UseVisualStyleBackColor = true;
            this.btnBigtree.Click += new System.EventHandler(this.btnBigtree_Click);
            // 
            // btnBigpipe
            // 
            this.btnBigpipe.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnBigpipe.BackgroundImage")));
            this.btnBigpipe.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnBigpipe.Location = new System.Drawing.Point(21, 184);
            this.btnBigpipe.Name = "btnBigpipe";
            this.btnBigpipe.Size = new System.Drawing.Size(60, 60);
            this.btnBigpipe.TabIndex = 2;
            this.btnBigpipe.UseVisualStyleBackColor = true;
            this.btnBigpipe.Click += new System.EventHandler(this.btnBigpipe_Click);
            // 
            // btnGrass
            // 
            this.btnGrass.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnGrass.BackgroundImage")));
            this.btnGrass.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnGrass.Location = new System.Drawing.Point(108, 15);
            this.btnGrass.Name = "btnGrass";
            this.btnGrass.Size = new System.Drawing.Size(60, 60);
            this.btnGrass.TabIndex = 1;
            this.btnGrass.UseVisualStyleBackColor = true;
            this.btnGrass.Click += new System.EventHandler(this.btnGrass_Click);
            // 
            // btnCloud
            // 
            this.btnCloud.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnCloud.BackgroundImage")));
            this.btnCloud.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnCloud.Location = new System.Drawing.Point(21, 15);
            this.btnCloud.Name = "btnCloud";
            this.btnCloud.Size = new System.Drawing.Size(60, 60);
            this.btnCloud.TabIndex = 0;
            this.btnCloud.UseVisualStyleBackColor = true;
            this.btnCloud.Click += new System.EventHandler(this.btnCloud_Click);
            // 
            // ObjectGame
            // 
            this.ObjectGame.BackColor = System.Drawing.Color.Silver;
            this.ObjectGame.Controls.Add(this.button10);
            this.ObjectGame.Controls.Add(this.button9);
            this.ObjectGame.Controls.Add(this.button8);
            this.ObjectGame.Controls.Add(this.button7);
            this.ObjectGame.Controls.Add(this.button6);
            this.ObjectGame.Controls.Add(this.button5);
            this.ObjectGame.Controls.Add(this.button4);
            this.ObjectGame.Controls.Add(this.button3);
            this.ObjectGame.Controls.Add(this.button2);
            this.ObjectGame.Controls.Add(this.button1);
            this.ObjectGame.Location = new System.Drawing.Point(4, 22);
            this.ObjectGame.Name = "ObjectGame";
            this.ObjectGame.Padding = new System.Windows.Forms.Padding(3);
            this.ObjectGame.Size = new System.Drawing.Size(192, 430);
            this.ObjectGame.TabIndex = 1;
            this.ObjectGame.Text = "ObjectGame";
            // 
            // button10
            // 
            this.button10.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button10.BackgroundImage")));
            this.button10.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button10.Location = new System.Drawing.Point(108, 349);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(60, 60);
            this.button10.TabIndex = 9;
            this.button10.UseVisualStyleBackColor = true;
            this.button10.Click += new System.EventHandler(this.button10_Click);
            // 
            // button9
            // 
            this.button9.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button9.BackgroundImage")));
            this.button9.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button9.Location = new System.Drawing.Point(21, 349);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(60, 60);
            this.button9.TabIndex = 8;
            this.button9.UseVisualStyleBackColor = true;
            this.button9.Click += new System.EventHandler(this.button9_Click);
            // 
            // button8
            // 
            this.button8.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button8.BackgroundImage")));
            this.button8.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button8.Location = new System.Drawing.Point(108, 266);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(60, 60);
            this.button8.TabIndex = 1;
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            // 
            // button7
            // 
            this.button7.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button7.BackgroundImage")));
            this.button7.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button7.Location = new System.Drawing.Point(21, 100);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(60, 60);
            this.button7.TabIndex = 7;
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // button6
            // 
            this.button6.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button6.BackgroundImage")));
            this.button6.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button6.Location = new System.Drawing.Point(108, 100);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(60, 60);
            this.button6.TabIndex = 6;
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button5
            // 
            this.button5.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button5.BackgroundImage")));
            this.button5.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button5.Location = new System.Drawing.Point(21, 184);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(60, 60);
            this.button5.TabIndex = 5;
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button4
            // 
            this.button4.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button4.BackgroundImage")));
            this.button4.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button4.Location = new System.Drawing.Point(21, 266);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(60, 60);
            this.button4.TabIndex = 4;
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button3
            // 
            this.button3.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button3.BackgroundImage")));
            this.button3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button3.Location = new System.Drawing.Point(108, 184);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(60, 60);
            this.button3.TabIndex = 3;
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button2
            // 
            this.button2.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button2.BackgroundImage")));
            this.button2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button2.Location = new System.Drawing.Point(108, 15);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(60, 60);
            this.button2.TabIndex = 2;
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button1
            // 
            this.button1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button1.BackgroundImage")));
            this.button1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button1.Location = new System.Drawing.Point(21, 15);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(60, 60);
            this.button1.TabIndex = 1;
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // DrawRect
            // 
            this.DrawRect.Location = new System.Drawing.Point(247, 49);
            this.DrawRect.Name = "DrawRect";
            this.DrawRect.Size = new System.Drawing.Size(129, 23);
            this.DrawRect.TabIndex = 7;
            this.DrawRect.Text = "Draw Rectangle";
            this.DrawRect.UseVisualStyleBackColor = true;
            this.DrawRect.Click += new System.EventHandler(this.DrawRect_Click);
            this.DrawRect.KeyDown += new System.Windows.Forms.KeyEventHandler(this.DrawRect_KeyDown);
            // 
            // MapEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(970, 486);
            this.Controls.Add(this.DrawRect);
            this.Controls.Add(this.TabBackGround);
            this.Controls.Add(this.PnContain);
            this.Controls.Add(this.menuGame);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuGame;
            this.MaximizeBox = false;
            this.Name = "MapEditor";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Map_Editor";
            this.Load += new System.EventHandler(this.MapEditor_Load);
            this.menuGame.ResumeLayout(false);
            this.menuGame.PerformLayout();
            this.PnContain.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.ptbContain)).EndInit();
            this.TabBackGround.ResumeLayout(false);
            this.BackGround.ResumeLayout(false);
            this.ObjectGame.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuGame;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ImageList imageList;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.Panel PnContain;
        private System.Windows.Forms.PictureBox ptbContain;
        private System.Windows.Forms.TabControl TabBackGround;
        private System.Windows.Forms.TabPage ObjectGame;
        private System.Windows.Forms.TabPage BackGround;
        private System.Windows.Forms.Button btnHouse;
        private System.Windows.Forms.Button btnFence;
        private System.Windows.Forms.Button btnMediumPipe;
        private System.Windows.Forms.Button btnSmalltree;
        private System.Windows.Forms.Button btnMountain;
        private System.Windows.Forms.Button btnSmallPipe;
        private System.Windows.Forms.Button btnBigtree;
        private System.Windows.Forms.Button btnBigpipe;
        private System.Windows.Forms.Button btnGrass;
        private System.Windows.Forms.Button btnCloud;
        private System.Windows.Forms.Button button10;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ToolStripMenuItem loadToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveTreeToolStripMenuItem;
        private System.Windows.Forms.Button DrawRect;
    }
}

