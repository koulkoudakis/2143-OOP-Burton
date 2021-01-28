## A05

- Name: Francis Popperpot
- Date: 28 Jan 2021
- Class: 2143 OOP

## Definitions

#### Class

> A class is basically a 'recipe' for creating objects. Its properties (or attributes) and methods (or member functions) are defined within the class. In other words, it is a blueprint for creating objects when a program runs. Classes can be built-in to the language or programmer-defined.
> 
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>


#### Object
> An object is the 'product' of a class that only exists when it is instantiated within a program. If a class is a recipe for a wedding cake, the object is the wedding cake. THe wedding cake exists only after runtime starts at the bakery, and the wedding cake doesn't (or shouldn't, anyway) exist after the wedding (program ends).

#### Method
> Methods are special functions that are defined within a class. They allow objects to do 'special' things and in many cases, have exclusive access to data that is stored within the object itself. For a car object, honking could be one of the methods that can only be accessed from *within* the car. 

#### Abstraction
> Abstraction is a concept that in layman's terms implies ", if it's complicated, keep it under the hood". Abstraction is basically the act of showing only important information to the user, keeping unrelated or unnecessary information out of clear sight. This can help increase user efficiency and avoid a lot of confusion!

#### Attributes/Properties
> Attributes are variables stored within an object. For a combat jet object, its current airspeed and heading would be attributes specific and unique to that instance of the combat jet class.

#### Class Variable
> Class variables (AKA static variables)are variables defined within the class, that all objects instantiated from that class basically depend upon. For example, there are thousands of instances of the A10-C Warthog object, but their model name and original designer are class variables that are in common with all of them.

#### Composition
> Composition is basically the concept of having classes refer to other classes in instance variables, making things a lot more complicated an intertwined, but allowing for greater capabilities. This allows for objects to have relationships with eachother (as nature intended). For example, the human body class has digestive system organs classes defined within it, which in turn may refer to the circulatory system for some methods or attributes, which refer to the brain class in some shape or form.

#### Constructor
> Constructors are special functions that are used to create (or instantiate) objects. An object's attributes may be determined at instantiation by passing parameters in to this constructor function.

#### Encapsulation
> Encapsulation is the concept of centralizing data and related methods into one coherent unit (class). That way, methods that act upon that related data can only be used within an instance of that class. This is useful for hiding data and generally keeping things organized and neat.

#### Friends
> Often confused with the sitcom, friends are functions that allow access to private attributes from outside the class, as if it were a private member function. This is like giving your house keys to a trusted distant family member for use in case of emergency or house-sitting.

#### Inheritance
> This is basically the concept of having one class being based upon another, more general class. For example, a tiger (child class) would inherit certain common traits from the (parent) feline class (such as having four legs). That feline class may inherit traits from the vertabrate class (having bones). This may save a lot of time and effort in having to define all necessary attributes separately for two classes that only have slight differences (eg. Lion and Tiger class should just inherit from the feline class).

#### Instance variable
> This is a variable that is specific to one instance of a class. DNA sequence would be an attribute that is unique to each person object (with the exception of twins).

#### Member variable
> A member variable is specific to one instance of a class, but is accessible by all of its member functions. The TV remote my be accessible by all members of the family in a house, but not by anyone outside the house.

#### Methods
> Methods are functions defined within a class that can access and work upon data within the class. Methods act upon variables within the class. Your breathing method acts upon *your* cells - you can't really breathe for someone else's body, can you?

#### Multiple inheritance
> This is basically the concept of having a class inherit methods or attributes from more than on parent class. This allows for more capability for each instance of such a child class, but increases complexity.
><img src="https://media.geeksforgeeks.org/wp-content/uploads/diamondproblem.png" width=250>

#### Overloading
> Overloading involves having the ability to input additional parameter types into a function or operator, to then allow that function to do specific different actions based on what type of data is input. For example a functions that adds integers 23 to 23 would result in 46 but inputting the strings '23' and '23' would result in the string '2323' via concatenation.

#### Polymorphism
> Polymorphism allows an object to exist in many different forms with different behaviours depending on the context within it is used. For example, circles and squares could be children of the shapes class, but when the showCorners() function is called, circles would return 0 and squares would return 4.

#### Public / Private / Protected
> These keyword basically differentiate who has access to the attributes and methods defined under them. Public attributes and methods may be access from outside the class, private attributes and methods may only be accessed by the current class, and protected attributes and methods may only be accessed by the current class or subclasses.

#### Static 
> The static keyword implies that a variable declared should exist and keep its value for the entire runtime of the program or between invocations of a function where it is defined. In another context, static variables defined within classes are shared by all instances of the class

#### Virtual
> Virtual, in the context of methods, are functions that are declared in a parent class that are overridden (or re-defined) in a child class. Virtual methods help with polymorphism. For example, greet() is defined as a virtual function within the Animal class, but greet() is overridden to output "bark" for the Dog class and "meow" for the Cat class.

#### ETC...
