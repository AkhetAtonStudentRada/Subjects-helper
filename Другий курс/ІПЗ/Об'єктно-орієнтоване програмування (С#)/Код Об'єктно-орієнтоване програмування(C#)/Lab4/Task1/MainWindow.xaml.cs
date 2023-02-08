using System;
using System.Collections.Generic;
using System.Windows;
using Task1Lib;

namespace Task1;

public partial class MainWindow : Window
{
    private City<string> city = new City<string>();
    public MainWindow()
    {
        InitializeComponent();

        city.Districts = new List<District>() { new District("", 0) };

        InitGrid();
    }

    private void InitGrid()
    {
        DataGridA.ItemsSource = city.Districts;
        DataGridA.CanUserAddRows = false;
    }

    private void MenuItemOpen_Click(object sender, RoutedEventArgs e)
    {
        Microsoft.Win32.OpenFileDialog dlg = new();
        dlg.InitialDirectory = System.AppDomain.CurrentDomain.BaseDirectory;
        dlg.DefaultExt = ".xml";
        dlg.Filter = "Файли XML (*.xml)|*.xml|Усі файли (*.*)|*.*";
        if (dlg.ShowDialog() == true)
        {
            try
            {
                city.ReadFromXml(dlg.FileName);
            }
            catch (Exception)
            {
                MessageBox.Show("Error reading from file");
            }
            InitGrid();
        }
    }

    private void MenuItemSave_Click(object sender, RoutedEventArgs e)
    {
        Microsoft.Win32.SaveFileDialog dlg = new();
        dlg.InitialDirectory = System.AppDomain.CurrentDomain.BaseDirectory;
        dlg.DefaultExt = ".xml";
        dlg.Filter = "Файли XML (*.xml)|*.xml|Усі файли (*.*)|*.*";
        if (dlg.ShowDialog() == true)
        {
            try
            {
                city.WriteToXml(dlg.FileName);
            }
            catch (Exception)
            {
                MessageBox.Show("Error writing to file");
            }
        }
    }

    private void ButtonSortByNameDesc_Click(object sender, RoutedEventArgs e)
    {
        city.SortByNameAlphabeticallyDescending();
        InitGrid();
    }

    private void ButtonSortByPopulation_Click(object sender, RoutedEventArgs e)
    {
        city.SortByPopulation();
        InitGrid();
    }

    private void ButtonSearchByName_Click(object sender, RoutedEventArgs e)
    {
        if (TextBoxSearchName.Text == "")
            return;

        string name = TextBoxSearchName.Text;
        var data = city.GetDistrictsWithName(name);

        string result = "";
        foreach (var item in data)
        {
            result += item + "\n";
        }
        MessageBox.Show(result, "Searh result:");
    }        
    
    private void ButtonSearchByPopulation_Click(object sender, RoutedEventArgs e)
    {
        if (TextBoxSearchPopulationFrom.Text == "" || TextBoxSearchPopulationTo.Text == "")
            return;

        int from = int.Parse(TextBoxSearchPopulationFrom.Text);
        int to = int.Parse(TextBoxSearchPopulationTo.Text);
        var data = city.GetDistrictsWithPopulation(from, to);

        string result = "";
        foreach (var item in data)
        {
            result += item + "\n";
        }
        MessageBox.Show(result, "Searh result:");
    }        
    
    private void MenuItemAdd_Click(object sender, RoutedEventArgs e)
    {
        DataGridA.CommitEdit();

        city += new District("", 0);

        InitGrid();
    }        
    
    private void MenuItemRemove_Click(object sender, RoutedEventArgs e)
    {
        int index = DataGridA.SelectedIndex;

        DataGridA.CommitEdit();

        city.Districts.RemoveAt(index);

        if (city.Districts.Count == 0)
        {
            city = new City<string>();
            city += new District("", 0);
            InitGrid();
        }

        DataGridA.ItemsSource = null;

        InitGrid();
    }
}
