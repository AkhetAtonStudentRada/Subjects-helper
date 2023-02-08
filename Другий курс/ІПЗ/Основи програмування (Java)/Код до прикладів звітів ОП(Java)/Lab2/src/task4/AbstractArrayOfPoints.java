package task4;

abstract class AbstractArrayOfPoints {
    public abstract void setPoint(int i, double x, double y);

    public abstract double getX(int i);

    public abstract double getY(int i);

    public abstract int count();

    public abstract void addPoint(double x, double y);

    public abstract void removeLast();

    public void sortByX() {
        boolean mustSort;
        do {
            mustSort = false;
            for (int i = 0; i < count() - 1; i++) {
                if (getX(i) > getX(i + 1)) {
                    double x = getX(i);
                    double y = getY(i);
                    setPoint(i, getX(i + 1), getY(i + 1));
                    setPoint(i + 1, x, y);
                    mustSort = true;
                }
            }
        }
        while (mustSort);
    }

    public void sortByY() {
        boolean mustSort;
        do {
            mustSort = false;
            for (int i = 0; i < count() - 1; i++) {
                if (getY(i) > getY(i + 1)) {
                    double x = getX(i);
                    double y = getY(i);
                    setPoint(i, getX(i + 1), getY(i + 1));
                    setPoint(i + 1, x, y);
                    mustSort = true;
                }
            }
        }
        while (mustSort);
    }

    @Override
    public String toString() {
        String s = "";
        for (int i = 0; i < count(); i++) {
            s += "x = " + getX(i) + " \ty = " + getY(i) + "\n";
        }
        return s + "\n";
    }

    public void test() {
        this.addPoint(4, 3);
        this.addPoint(2, 4);
        this.addPoint(3, 1);
        this.addPoint(5, 3);
        System.out.println(this);
        this.setPoint(3, 0, 0);
        System.out.println(this);
        this.removeLast();
        System.out.println(this);
        System.out.println("Sorted by x:");
        this.sortByX();
        System.out.println(this);
        System.out.println("Sorted by y:");
        this.sortByY();
        System.out.println(this);
    }
}
