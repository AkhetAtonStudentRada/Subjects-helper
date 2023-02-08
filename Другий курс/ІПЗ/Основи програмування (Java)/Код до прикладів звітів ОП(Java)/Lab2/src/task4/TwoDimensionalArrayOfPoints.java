package task4;

class TwoDimensionalArrayOfPoints extends AbstractArrayOfPoints {
    private double[][] points = new double[][]{};

    @Override
    public void setPoint(int i, double x, double y) {
        if(i >= 0 && i < this.count()){
            this.points[i][0] = x;
            this.points[i][1] = y;
        }
    }

    @Override
    public double getX(int i) {
        return i >= 0 && i < this.count() ? this.points[i][0] : 0;
    }

    @Override
    public double getY(int i) {
        return i >= 0 && i < this.count() ? this.points[i][1] : 0;
    }

    @Override
    public int count() {
        return this.points.length;
    }

    @Override
    public void addPoint(double x, double y) {
        double[][] temp = new double[points.length + 1][2];
        System.arraycopy(points, 0, temp, 0, points.length);
        temp[temp.length - 1][0] = x;
        temp[temp.length - 1][1] = y;
        points = temp;
    }

    @Override
    public void removeLast() {
        if (count() == 0)
            return;

        double[][] temp = new double[points.length - 1][2];
        System.arraycopy(points, 0, temp, 0, temp.length);
        points = temp;
    }
}
