import java.util.Vector;
import portDataBase.W_LOCATION;

public class LocationDBAdapter {
  /* {author=Christopher Foley}*/


	 private LocationDBAdapter() {
	  }

  public void updateDb() {
  /* {author=Christopher Foley}*/
	  W_LOCATION.write();		// write what you need to
  }

 

  public SimpleLocation findLocation(Integer searchLocation) {
	  W_LOCATION.search();
	  
  return null;
  }

}