package com.tgeorge.challenges;

public class Cell
{
	private int currentNum;
	private int cycleLength;

	public Cell(int currentNum, int cycleLength)
	{
		this.currentNum = currentNum;
		this.cycleLength = cycleLength;
	}

	public int getCurrentNum()
	{
		return currentNum;
	}

	public int getCycleLength()
	{
		return cycleLength;	
	}

	public void setCurrentNum(int currentNum)
	{
		this.currentNum = currentNum;
	}

	public void setCycleLength(int cycleLength)
	{
		this.cycleLength = cycleLength;
	}
	
	public String toString()
	{
		return getCurrentNum() + "  ";
	}
}
