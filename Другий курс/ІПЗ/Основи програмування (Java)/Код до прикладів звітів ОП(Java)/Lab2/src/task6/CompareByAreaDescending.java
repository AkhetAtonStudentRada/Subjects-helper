package task6;

import java.util.Comparator;

class CompareByAreaDescending implements Comparator<Triangle> {
    @Override
    public int compare(Triangle tr1, Triangle tr2) {
        return -1 * Double.compare(tr1.area(), tr2.area());
    }
}