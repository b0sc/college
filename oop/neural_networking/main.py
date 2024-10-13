class Neuron:
    def __init__(self, weights):
        self.weights = weights

    def activate(self, inputs):
        # Simplified activation function for demonstration purposes
        return sum(w * x for w, x in zip(self.weights, inputs))

class NeuralNetwork:
    def __init__(self, layers):
        self.layers = [Neuron(weights) for weights in layers]

    def predict(self, inputs):
        layer_outputs = [neuron.activate(inputs) for neuron in self.layers]
        return layer_outputs

# Usage
network = NeuralNetwork([[0.5, 0.2], [0.3, 0.8]])
result = network.predict([0.6, 0.4])
print(result)