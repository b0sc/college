class Product:
    def __init__(self, name, price, quantity):
        self.name = name
        self.price = price
        self.quantity = quantity

class ShoppingCart:
    def __init__(self):
        self.items = []

    def add_item(self, product, quantity):
        self.items.append({"product": product, "quantity": quantity})

    def calculate_total(self):
        total = sum(item["product"].price * item["quantity"] for item in self.items)
        return total

# Usage
product1 = Product("Laptop", 1000, 2)
product2 = Product("Headphones", 100, 3)

cart = ShoppingCart()
cart.add_item(product1, 1)
cart.add_item(product2, 2)

total_price = cart.calculate_total()
print(f"Total Price: ${total_price}")