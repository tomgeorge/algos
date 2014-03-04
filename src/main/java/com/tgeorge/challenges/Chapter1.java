package com.tgeorge.challenges;
import com.tgeorge.challenges.Cell;
import java.util.ArrayList;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;


public class Chapter1
{
	public static void threenplusone(String[] args) {
		System.out.println("Hello");
		int low = new Integer(args[0]).intValue();	
		int high = new Integer(args[1]).intValue();	
		System.out.print(low + " " + high + " ");
		int[] cycleLength = new int[(high - low) + 1];
		int maxCycle = -1;
		ArrayList<Cell> sequence = new ArrayList<Cell>();
		for (int i = low; i <= high; i++) {
			sequence = generate(i);
			cycleLength[i - low] = maxCycle(sequence);
			if(maxCycle < cycleLength[i - low]) {
				maxCycle = cycleLength[i - low];
			}
		}
		System.out.print(maxCycle + "\n");
	}

	public static void minesweeper(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		int[][] field;
		int height = -1, width = -1;
		int curRow = 0;
		String tmp;
		while((tmp = in.readLine()) != null) {
				if(tmp.contains(" ")) {
						String[] nums = tmp.split(" ");
						height = new Integer(nums[0]).intValue();
						width = new Integer(nums[1]).intValue();
				} else {
						field = new int[height][width];
				}	

		}
		in.close();
	}
			
	public static void main(String[] args) throws IOException {
		//threenplusone(args);
		minesweeper(args);
	}
	
	public static ArrayList<Cell> generate(int n)
	{
		ArrayList<Cell> cycles = new ArrayList<Cell>();
		int cycle = 1;
		cycles.add(new Cell(n, cycle));
		while(n != 1)
		{
			if(n %2 == 0) {
				cycle = cycle + 1;
				cycles.add(new Cell(n / 2, cycle));
				n = n /2;
				continue;
			}
			if(n % 2 == 1) {
				cycle = cycle + 1;
				cycles.add(new Cell((n * 3) + 1, cycle));
				n = (n*3) + 1;
				continue;
			}
		}
		return cycles;
	}

	public static int maxCycle(ArrayList<Cell> cells)
	{
		return cells.get(cells.size() - 1).getCycleLength();
	}
}

