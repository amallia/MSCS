import portDataBase.CARGO_UNIT;

public class ContainerDbAdaptor {
	/* {author=Christopher Foley}*/


	public Vector  myCARGO_UNIT;

	public void createRecord(Containter container) {
		myCARGO_UNIT.create();
	}

	public Container locate()
	{
		myCARGO_UNIT.search();
		return null
	}

	public Container get()
	{
		myCARGO_UNIT.read();
	}

	public boolean delete()
	{
		return myCARGO_UNIT.delete();
	}

	public boolean updateRecord()
	{
		return myCargoUnit.write();
	}

}