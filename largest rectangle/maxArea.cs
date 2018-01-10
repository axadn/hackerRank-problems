using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution {
	static long largestRectangle(int[] h) {
		Stack<int> maxStack = new Stack<int>();
		int maxArea = 0;
		int leftIdx;
		int topIdx;
		for(int i = 0; i < h.Length; ++i){
			if(maxStack.Count == 0 || h[i] > h[maxStack.Peek()]){
				maxStack.Push(i);
			}
			else{
				while(maxStack.Count != 0 && h[maxStack.Peek()] > h[i]){
					topIdx = maxStack.Pop();
					maxArea = Math.Max(maxArea, h[topIdx] * (
						i - (maxStack.Count == 0 ? 0 : maxStack.Peek() + 1)
					));
				}
				if(maxStack.Count == 0 || maxStack.Peek()!= h[i]){
					maxStack.Push(i);
				}
			}
		}
		while(maxStack.Count != 0){
			maxArea = Math.Max(maxArea, h[maxStack.Peek()] * (h.Length - maxStack.Pop()));
		}
		return maxArea;
	}

	static void Main(String[] args) {
		int n = Convert.ToInt32(Console.ReadLine());
		string[] h_temp = Console.ReadLine().Split(' ');
		int[] h = Array.ConvertAll(h_temp,Int32.Parse);
		long result = largestRectangle(h);
		Console.WriteLine(result);
	}
}
