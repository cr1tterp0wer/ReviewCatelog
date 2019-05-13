package com.cr1tterp0wer.linkedlist;

public class Person {

	public String name;
	public String address;
	public char sex;
	public int age;
	public String phone;
	public float height;
	
	public Person(String n, String addr, char s, int a, String p, float h) {
		name = n;
		address = addr;
		sex = s;
		age = a;
		phone = p;
		height = h;
	}
	@Override
	public String toString() {
		return "Name: " + name + " Address: " + address +
				" Sex: " + sex + " Age: " + age + " Phone: "
				+ phone + " Height: " + height;
	}
}
