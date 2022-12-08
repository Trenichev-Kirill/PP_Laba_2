using System;
using System.Windows;
using System.Windows.Media;

namespace lab2Win12._10._22
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            dlg.FileName = "Document";
            dlg.DefaultExt = ".mp4";
            dlg.Filter = "Video (.mp4)|*.mp4";
            Nullable<bool> result = dlg.ShowDialog();
            MediaPlayer player = new MediaPlayer();
            if (result == true)
            {
                string filename = dlg.FileName;
                myPlayer.Source = new Uri(filename, UriKind.Relative);
                myPlayer.Play();
            }
        }
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            myPlayer.Play();
        }
        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            myPlayer.Pause();
        }
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            myPlayer.Stop();
        }
        private void ChangeMediaVolume(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            myPlayer.Volume = (double)volumeSlider.Value;
        }
    }
}
