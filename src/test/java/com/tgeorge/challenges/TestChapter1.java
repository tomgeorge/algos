import static org.junit.Assert.*;
import java.util.ArrayList; 
import com.tgeorge.challenges.Chapter1;
import com.tgeorge.challenges.Cell;

public class TestChapter1
{
    private int[] anumber;
    private int[] acycleLength;
    private ArrayList<Cell> cycleLength;

    public void setUp()
    {
        anumber = new int[] { 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1 };
        acycleLength = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
        for (int i = 0; i < anumber.length; i++) {
                Cell c = new Cell(anumber[i], acycleLength[i]);
                cycleLength.add(c);
        }
    }

	public void testGenerate()
	{
        assertEquals("Test 1", Chapter1.generate(22), cycleLength);
	} 
}
