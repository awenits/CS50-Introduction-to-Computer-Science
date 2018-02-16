import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        #loads positive words into memory
        self.positives = set()
        file = open(positives, "r")
        for line in file:
            if line.startswith(';') == False:
                self.positives.add(line.rstrip("\n"))
        file.close()
        
        #loads negative words into memory
        self.negatives = set()
        file = open(negatives, "r")
        for line in file:
            if line.startswith(';') == False:
                self.negatives.add(line.rstrip("\n"))
        file.close()


    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score = 0
        for token in tokens:
            if token.lower() in self.positives:
                score += 1
            elif token.lower() in self.negatives:
                score -= 1
            else:
                continue
        
        return score
