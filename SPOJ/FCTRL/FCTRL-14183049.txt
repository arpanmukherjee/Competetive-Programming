import java.io.InputStream;
import java.io.OutputStream;
 
public class Main {
    private static ChefInputHandler in;
    private static ChefOutputHandler out;
 
    static int zeros (int n){
        if (n<5) return 0;
        else return zeros(n/5)+n/5;
    }
    
    public static void main(String[] args) {
        try {
            in = new ChefInputHandler(System.in);
            out = new ChefOutputHandler(System.out);
            
            run();
            
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private static void run() throws Exception {
        int currentNumber = 0;
        
        // number of lines
        int t = in.getInt();
        
        // loop through lines
        while (t > 0) {
            currentNumber = in.getInt();
            
            out.writeInt(zeros(currentNumber));
            out.newLine();
            
            t--;
        }
    }
    
    // hopefully a fast input handler for CodeChef problems
    public static class ChefInputHandler {
        private static final int BUFF_SIZE = 8192;
        private static final byte SPACE = ' ';
        private static final byte MINUS_SIGN = '-';
        private static final byte ZERO = '0';
        private static final byte NINE = '9';
        
        private byte[] buffer;
        private InputStream is;
        private int index;
        private int bytesRead;
        
        public ChefInputHandler(InputStream inputStream) {
            is = inputStream;
            buffer = new byte[BUFF_SIZE];
            index = bytesRead = 0;
        }
        
        public String getString() throws Exception {
            StringBuffer buf = new StringBuffer();
            
            // get the next character
            byte currentByte = getNextByte();
            
            // chew through whitespace
            while (currentByte <= SPACE) {
                currentByte = getNextByte();
            }
            
            // get the string
            do {
                buf.append((char) currentByte);
                currentByte = getNextByte();
            } while (currentByte > SPACE);
            
            return buf.toString();
        }
        
        // moves past whitespace and returns the next int
        public int getInt() throws Exception {
            int retVal = 0;
            
            // get the next character
            byte currentByte = getNextByte();
            
            // chew through whitespace
            while (currentByte <= SPACE) {
                currentByte = getNextByte();
            }
            
            // now we're at the number (maybe) - handle a negative sign
            boolean isNegative = (currentByte == MINUS_SIGN);
            if (isNegative) {
                // read past the negative sign
                currentByte = getNextByte();
            }
            
            // now we're really at the number - build it
            do {
                retVal = (retVal * 10) + currentByte - ZERO;
                currentByte = getNextByte();
            } while (isDigit(currentByte));
            
            // handle negative value
            if (isNegative) {
                return -retVal;
            }
            
            return retVal;
        }
        
        private boolean isDigit(byte theByte) {
            return ((theByte >= ZERO) && (theByte <= NINE));
        }
        
        // fills the buffer if necessary and returns the next byte
        private byte getNextByte() throws Exception {
            if (index == bytesRead) {
                // we need more data - reset the index and read
                bytesRead = is.read(buffer, index=0, BUFF_SIZE);
            }
            
            // return the next byte in the buffer
            return buffer[index++];
        }
    }
    
    // hopefully a fast output handler for CodeChef problems
    public static class ChefOutputHandler {
        private static final int BUFF_SIZE = 8192;
        private static final char NEW_LINE = '\n';
        private static final char ZERO = '0';
        private static final char MINUS_SIGN = '-';
        
        private byte[] buffer;
        private OutputStream os;
        private int index;
        
        public ChefOutputHandler(OutputStream outputStream) {
            os = outputStream;
            buffer = new byte[BUFF_SIZE];
            index = 0;
        }
        
        public void writeString(String theString) throws Exception {
            for (int i=0; i<theString.length(); i++) {
                writeChar(theString.charAt(i));
            }
        }
        
        public void writeInt(int theInt) throws Exception {
            // handle zero - exit immediately
            if (theInt == 0) {
                writeChar(ZERO);
                return;
            }
            
            // handle negatives
            if (theInt < 0) {
                writeChar(MINUS_SIGN);
                theInt = -theInt;
            }
            
            // recursively handle the number
            if (theInt < 10) {
                // down to a single digit - write it
                writeChar((char) (theInt + ZERO));
            } else {
                // strip this digit for the next recursion
                writeInt(theInt/10);
                
                // write this digit
                writeChar((char) ((theInt % 10) + ZERO));
            }
        }
        
        public void newLine() throws Exception {
            writeChar(NEW_LINE);
        }
        
        public void writeChar(char theChar) throws Exception {
            if (index == BUFF_SIZE) {
                // the buffer's full
                flush();
            }
            
            buffer[index++] = (byte) theChar;
        }
        
        // write whatever we have waiting
        public void flush() throws Exception {
            if (index > 0) {
                // there is something to write
                os.write(buffer, 0, index);
                index = 0;
            }
        }
    }
}