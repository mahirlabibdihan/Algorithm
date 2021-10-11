import java.util.*;
import java.io.*;
public class Word_Counter{
    public static void main(String[] args) throws Exception{
    	int words=0;
    	int characters=0;
    	int sentences=0;

        BufferedReader br = new BufferedReader(new FileReader("I:/Presentation2.txt"));
        while (true) {
            String line = br.readLine();
            if (line == null) break;
            StringTokenizer st = new StringTokenizer(line);
            while(st.hasMoreTokens())
	    	{
	    		String t = st.nextToken();
	    		if(t.equals(".")) 
	    		{
	    			sentences++;
	    		}
	    		else if(t.equals(","))
	    		{
	    			continue;
	    		}
	    		else
	    		{
	    			words++;
	    			characters+=t.length();
	    		}
	    		
	    	}
        }
        br.close();

    	  	
    	System.out.println("Characters : "+characters+"\n"+
    						"Words : "+words+"\n"+
    						"Sentences : "+sentences);
 	}
}