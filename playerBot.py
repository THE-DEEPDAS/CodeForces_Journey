from typing import List, Optional, Tuple

class BaseBot:
    """Base class for UNO bots to inherit from."""
    def __init__(self, hand: List[str]):
        self.hand = hand
    
    def add_card(self, card: str):
        """Add a card to the bot's hand."""
        self.hand.append(card)
    
    def remove_card(self, card: str):
        """Remove a card from the bot's hand."""
        if card in self.hand:
            self.hand.remove(card)
    
    def choose_card(self, top_card: str) -> Optional[str]:
        """Choose a card to play based on the top card."""
        raise NotImplementedError("This method should be overridden by subclasses")


class Player(BaseBot):
    """Intelligent UNO-playing bot implementation."""
    
    def choose_card(self, top_card: str) -> Optional[str]:
        """
        Choose a card to play based on the top card.
        
        Args:
            top_card (str): The current top card on the discard pile.
            
        Returns:
            Optional[str]: The card to play, or None to draw.
        """
        # Parse the top card to get its color and value
        top_color, top_value = self._parse_card(top_card)
        
        # First, try to play a matching card (same color or value)
        for card in self.hand:
            card_color, card_value = self._parse_card(card)
            
            # Check if this is a valid move
            if self._is_valid_move(card, top_card):
                # Prioritize number cards first
                if card_value.isdigit():
                    return card
        
        # Try to play special cards next (Skip, Reverse, Draw Two)
        for card in self.hand:
            card_color, card_value = self._parse_card(card)
            
            if self._is_valid_move(card, top_card) and card_value in ['S', 'R', 'P']:
                return card
                
        # Try to play a wild card if nothing else works
        for card in self.hand:
            if card.startswith('W'):  # Wild or Wild Draw Four
                # Choose the most common color in hand for the wild
                new_color = self._choose_best_wild_color()
                return f"W{new_color}" if card == "W" else f"W4{new_color}"
        
        # If no valid card is found, draw a card
        return None
    
    def _parse_card(self, card: str) -> Tuple[str, str]:
        """
        Parse a card string into its color and value components.
        
        Args:
            card (str): Card string like "R5" or "W4R"
            
        Returns:
            Tuple[str, str]: The color and value
        """
        if card.startswith('W'):
            if len(card) == 1:  # Just a wild card
                return None, 'W'
            elif card.startswith('W4'):  # Wild Draw Four
                return card[2:] if len(card) > 2 else None, 'W4'
            else:  # Wild with color set
                return card[1:], 'W'
        else:
            return card[0], card[1:]
    
    def _is_valid_move(self, card: str, top_card: str) -> bool:
        """
        Check if a card is valid to play on the top card.
        
        Args:
            card (str): The card to check
            top_card (str): The current top card
            
        Returns:
            bool: True if the move is valid
        """
        card_color, card_value = self._parse_card(card)
        top_color, top_value = self._parse_card(top_card)
        
        # Wild cards can always be played
        if card_value in ['W', 'W4']:
            return True
        
        # Match by color or value
        return card_color == top_color or card_value == top_value
    
    def _choose_best_wild_color(self) -> str:
        """
        Choose the best color for a wild card based on the hand.
        
        Returns:
            str: The chosen color ('R', 'G', 'B', or 'Y')
        """
        color_counts = {'R': 0, 'G': 0, 'B': 0, 'Y': 0}
        
        for card in self.hand:
            if not card.startswith('W'):  # Skip wild cards
                color = card[0]
                if color in color_counts:
                    color_counts[color] += 1
        
        # Return the color that appears most frequently in hand
        best_color = max(color_counts.items(), key=lambda x: x[1])[0]
        return best_color
