using System.Data;

namespace Task6Lib;

public class DataArray
{
    public class DataArrayRow
    {
        private readonly DataTable data;
        private readonly int row;

        public DataArrayRow(DataTable data, int row)
        {
            this.row = row;
            this.data = data;
        }

        public double this[int index]
        {
            get => double.Parse(data.Rows[row][index] + "");
            set => data.Rows[row][index] = value;
        }
    }

    private readonly DataTable data = new();

    public int M { get; }

    public int N { get; }

    public DataTable Data
    {
        get => data;
    }

    public DataArrayRow this[int index]
    {
        get => new(data, index);
    }

    public DataArray(int m, int n)
    {
        M = m;
        N = n;

        for (int j = 1; j <= N; j++)
        {
            data.Columns.Add();
        }

        for (int i = 1; i <= M; i++)
        {
            data.Rows.Add();
        }
    }
}