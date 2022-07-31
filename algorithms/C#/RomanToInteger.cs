using System;

public class RomanConvert {
	public int RomanToInt(string s)
    {
		int numericValue = 0;

		// Loop through the roman numeric start to finish
		for (int i = (s.Length - 1); i >= 0; i--)
        {
            if ((i + 1) < s.Length )
            {
				// Debugging values
				var currentChar = s[i];
				var previousChar = s[i + 1];

				if (s[i] == 'I' &&  (s[i + 1] == 'V' || s[i + 1] == 'X'))
                {
					numericValue -= 1;
					continue;
				}
				if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                {
					numericValue -= 10;
					continue;
				}
				if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
				{
					numericValue -= 100;
					continue;
				}
            }

            if (s[i] == 'I')
				numericValue++;
			if (s[i] == 'V')
				numericValue += 5;
			if (s[i] == 'X')
				numericValue += 10;
			if (s[i] == 'L')
				numericValue += 50;
			if (s[i] == 'C')
				numericValue += 100;
			if (s[i] == 'D')
				numericValue += 500;
			if (s[i] == 'M')
				numericValue += 1000;
        }

		return numericValue;
    }
}

class LeetCodeProblems
{
	static void Main(string[] args)
	{
		var romNumeric = new RomanConvert();
		var convertedNumeric = romNumeric.RomanToInt("III");
		Console.WriteLine($"Roman numeric III is {convertedNumeric}");
		Console.WriteLine($"Roman numeric LVIII is {romNumeric.RomanToInt("LVIII")}");
		Console.WriteLine($"Roman numeric MCMXCIV is {romNumeric.RomanToInt("MCMXCIV")}");
	}
}

