package task;

public class typeConversion {
        public static int fromBool(boolean x){
            if (x==true){
                return 1;
            } else {
                return 0;
            }
        }

        public static boolean inBool(int x){
            if (x == 0){
                return false;
            } else {
                return true;
            }
        }
}
