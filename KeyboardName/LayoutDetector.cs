using System;
using System.ComponentModel.Design;
using System.Runtime.InteropServices;
using System.Text;

public class LayoutDetector
{
	[DllImport("user32.dll")]
	static extern IntPtr GetForegroundWindow();

	[DllImport("user32.dll")]
	static extern uint GetWindowThreadProcessId(IntPtr hwnd, IntPtr lpdwProcessId);

	[DllImport("user32.dll")]
	static extern IntPtr GetKeyboardLayout(uint idThread);

	public static string GetActiveLayoutName()
	{
		IntPtr hWnd = GetForegroundWindow();
		uint threadId = GetWindowThreadProcessId(hWnd, IntPtr.Zero);
		IntPtr hkl = GetKeyboardLayout(threadId);

		// Extract the language ID from the handle
		int langId = (int)hkl & 0xFFFF;
		var keyboardName = string.Empty;
		if (langId == 1051)
		{
			keyboardName = "Slovak";
			if ((ulong)hkl == 0xfffffffff013041bUL)
			{
				keyboardName += " (QWERTY)";
			}
			else
			{
				if ((ulong)hkl == 0x00000000041b041bUL)
				{
					keyboardName += " (QWERTZ)";
				}
				else
				{
					keyboardName += " (Slovak)";
				}
			}
		}
		else
		{
			keyboardName = new System.Globalization.CultureInfo(langId).DisplayName;
		}

		return keyboardName;
	}
}