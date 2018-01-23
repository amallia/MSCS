public class FragileContainerDecorator extends ContainerDecorator {
  /* {author=Christopher Foley}*/

  public static final boolean isFragile=true;
  public FragileContainerDecorator(Integer length, Integer width, Integer height, Integer tare, Integer netWeight, Integer maxWeight) {
	  super(length, width, height, tare, netWeight, maxWeight);
  }

} 