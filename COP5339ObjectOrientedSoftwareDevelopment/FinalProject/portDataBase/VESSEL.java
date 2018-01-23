package portDataBase;

import java.util.Vector;
import String;
import Boolean;
import Location;

public class VESSEL {
	/* {author=Christopher Foley}*/

	public static VESSEL myVESSELDB;
	public String name;

	public Location berth;

	private VESSEL()
	{
		if (myVESSELDB == null) myVESSELDB = this;
	}

	public VESSEL search(String shipName, String portOfRegistry) {
		System.out.println("search for db record here");
		return null;		// null indicates not found
	}

	public VESSEL create(String name, String registry) {
		System.out.println("create new vessel db record here");
		  System.out.println("create new location record here");

		return null;
	}

	public VESSEL read() {
		System.out.println("read ship db record here");
		return null;
	}

	public Boolean write() {
		System.out.println("write ship db record here");
		return false;
	}

	public Boolean delete() {
		System.out.println("delete ship db record here");
		return false;
	}

}