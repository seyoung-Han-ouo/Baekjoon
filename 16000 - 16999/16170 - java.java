import java.text.SimpleDateFormat;
import java.util.Date;

public class Main {
    public static void main(String[] args) {
        SimpleDateFormat date = new SimpleDateFormat("yyyy\nMM\ndd");
        String t = date.format(new Date());
        System.out.println(t);
    }
}