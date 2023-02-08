using System;
using System.Windows;
using Task6Lib;

namespace Task6;

public partial class MainWindow : Window
{
    private DataArray array;
    private int M = 2;
    private int N = 2;
    public MainWindow()
    {
        InitializeComponent();

        InitTable();
    }

    private void InitTable()
    {
        array = new DataArray(M, N);
        DataGridArray.ItemsSource = array.Data.DefaultView;
        for (int i = 0; i < array.M; i++)
        {
            for (int j = 0; j < array.N; j++)
            {
                array[i][j] = 0;
            }
        }
        DataGridArray.CanUserAddRows = false;
    }

    private void MenuItemNew_Click(object sender, RoutedEventArgs e)
    {
        TextBoxM.Text = "";
        TextBoxN.Text = "";
        InitTable();
        CheckBoxWindow.IsChecked = false;
    }

    private void MenuItemExit_Click(object sender, RoutedEventArgs e)
    {
        Close();
    }
    
    private void ButtonRandom_Click(object sender, RoutedEventArgs e)
    {
        Random random = new Random(DateTime.Now.Millisecond);

        for (int i = 0; i < array.M; i++)
        {
            for (int j = 0; j < array.N; j++)
            {
                array[i][j] = random.NextDouble() * 2000 - 1000;
            }
        }
    }
    
    private void ButtonCreate_Click(object sender, RoutedEventArgs e)
    {
        if (TextBoxM.Text == "" || TextBoxN.Text == "")
        {
            return;
        }

        M = int.Parse(TextBoxM.Text);
        N = int.Parse(TextBoxN.Text);

        InitTable();
    }
    
    private void ButtonResult_Click(object sender, RoutedEventArgs e)
    {
        try
        {
            double sum = 0;

            for (int i = 0; i < array.M; i++)
            {
                double product = 1;

                for (int j = 0; j < array.N; j++)
                {
                    product *= array[i][j];
                }

                sum += product;
            }

            if (CheckBoxWindow.IsChecked ?? true)
            {
                LabelResult.Content = "";
                MessageBox.Show("Result: " + sum);
            }
            else
            {
                LabelResult.Content = sum + "";
            }
        }
        catch (Exception)
        {
            MessageBox.Show("Wrong data!", "Error");
        }
    }
}
