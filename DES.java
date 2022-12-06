import javax.crypto.*;

public class DES
{    
	public static void main(String[] argv) {
		try{

		    KeyGenerator keygenerator = KeyGenerator.getInstance("DES");
		    SecretKey myDesKey = keygenerator.generateKey();
		    
		    Cipher desCipher;

		    // Create the cipher 
		    desCipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
		    
		    // Initialize the cipher for encryption
		    desCipher.init(Cipher.ENCRYPT_MODE, myDesKey);

		    //sensitive information
		    byte[] text = "Nikhil".getBytes();
		    System.out.println("Text [Byte Format] : ");
			for(int i=0;i<text.length;i++)
			System.out.print(text[i]+" ");
			System.out.println();
		    System.out.println("Text : " + new String(text));
		   
		    // Encrypt the text
		    byte[] textEncrypted = desCipher.doFinal(text);

		    System.out.println("Text Encryted : ");
		    for(int i=0;i<textEncrypted.length;i++)
			System.out.print(textEncrypted[i]+" ");
			System.out.println();

		    // Initialize the same cipher for decryption
		    desCipher.init(Cipher.DECRYPT_MODE, myDesKey);

		    // Decrypt the text
		    byte[] textDecrypted = desCipher.doFinal(textEncrypted);
		    
		    System.out.println("Text Decryted : " + new String(textDecrypted));
		    
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}