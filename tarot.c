#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int drawcard(string);
int get_random_number(int, int);
void printresults(int x);

int main(void)
{
    int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, spreadtype;
    string question;
    do
    {
        question = get_string("What is your question or focus?\n");
    }
    while (strcmp(question, "") == 0 || strlen(question) < 5);
    do
    {
    spreadtype = get_int("Choose a spread...\nPress 1 for a 3 card past/present/future spread or press 2 for a 10 card Celtic Cross: ");
    }
    while (spreadtype < 1 || spreadtype > 2);
    if (spreadtype == 1)
    {
        card1 = drawcard("past");
        card2 = drawcard("present");
        card3 = drawcard("future");
        printf("You drew card numbers %i, %i, and %i respectively.\n", card1, card2, card3);
        printf("         ______    ______    ______    \n");
        printf("        |P     |  |PR    |  |FU    |  \n");
        printf("        | A    |  | ES   |  | TU   |  \n");
        printf("        |  S   |  |  EN  |  |  RE  |  \n");
        printf("        |___T__|  |____T_|  |______|  \n");
        printf("           %i        %i        %i     \n\n", card1, card2, card3);
        printf("In the past position:\n");
        printresults(card1);
        printf("In the present position:\n");
        printresults(card2);
        printf("In the future position:\n");
        printresults(card3);
    }
    else
    {
        card1 = drawcard("present");
        card2 = drawcard("challenge");
        card3 = drawcard("subconscious");
        card4 = drawcard("past");
        card5 = drawcard("future");
        card6 = drawcard("near future");
        card7 = drawcard("internal influences");
        card8 = drawcard("external influences");
        card9 = drawcard("hopes and fears");
        card10 = drawcard("outcome");
        printf("You drew card numbers %i, %i, %i, %i, %i, %i, %i, %i, %i, and %i respectively.\n", card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
        printf("                                                  ______   \n");
        printf("                        ______                   |      |  \n");
        printf("                       |      |                  | OUT  |  \n");
        printf("                       |FUTURE|                  | COME |  \n");
        printf("                       |      |                  |______|  \n");
        printf("                       |______|                     %i     \n", card10);
        printf("                          %i                               \n", card5);
        printf("                                                  ______   \n");
        printf("              ______    ______    ______         |      |  \n");
        printf("             |      |  |PRE   |  |      |        |HOPES&|  \n");
        printf("             | PAST |  | SENT |  | NEAR |        | FEARS|  \n");
        printf("             |      |  |      |  |FUTURE|        |______|  \n");
        printf("             |___ __|  |______|  |______|           %i     \n", card9);
        printf("                %i        %i         %i                    \n", card4, card1, card6);
        printf("                                                  ______   \n");
        printf("                       _________                 |      |  \n");
        printf("                      |         |                |EXTERN|  \n");
        printf("                      |CHALLENGE|                | INFL.|  \n");
        printf("                      |_________|                |______|  \n");
        printf("                          %i                        %i     \n", card2, card8);
        printf("                                                           \n");
        printf("                        ______                    ______   \n");
        printf("                       |      |                  |      |  \n");
        printf("                       | SUB  |                  |INTERN|  \n");
        printf("                       |CONSC.|                  | INFL.|  \n");
        printf("                       |______|                  |______|  \n");
        printf("                          %i                        %i     \n\n", card3, card7);
        printf("In the present position:\n");
        printresults(card1);
        printf("In the challenge position:\n");
        printresults(card2);
        printf("In the subconscious position:\n");
        printresults(card3);
        printf("In the past position:\n");
        printresults(card4);
        printf("In the future position:\n");
        printresults(card5);
        printf("In the near future position:\n");
        printresults(card6);
        printf("In the internal influences position:\n");
        printresults(card7);
        printf("In the external influences position:\n");
        printresults(card8);
        printf("In the hopes and fears position:\n");
        printresults(card9);
        printf("In the outcome position:\n");
        printresults(card10);
    }
}

int drawcard(string cardtype)
{
    int start;
    do
    {
        start = get_int("Press 1 to shuffle the deck and draw a %s card: ", cardtype);
    }
    while (start != 1);

    int card = get_random_number(1, 22);

    return card;
}

int get_random_number(int lower, int upper) 
{ 
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num;
} 

void printresults(int x)
{
    switch(x)
    {
        case 1:
            printf("The Fool\nBeginnings, innocence, spontaneity, a free spirit\nThe Fool is numbered 0 – the number of unlimited potential – and so does not have a specific place in the sequence of the Tarot cards. The Fool can be placed either at the beginning of the Major Arcana or at the end. The Major Arcana is often considered the Fool’s journey through life and as such, he is ever present and therefore needs no number.\n\nOn the Fool Tarot card, a young man stands on the edge of a cliff, without a care in the world, as he sets out on a new adventure. He is gazing upwards toward the sky (and the Universe) and is seemingly unaware that he is about to skip off a precipice into the unknown. Over his shoulder rests a modest knapsack containing everything he needs – which isn’t much (let’s say he’s a minimalist). The white rose in his left hand represents his purity and innocence. And at his feet is a small white dog, representing loyalty and protection, that encourages him to charge forward and learn the lessons he came to learn. The mountains behind the Fool symbolise the challenges yet to come. They are forever present, but the Fool doesn’t care about them right now; he’s more focused on starting his expedition.\n\n\n");
            break;
        case 2:
            printf("The Magician\nManifestation, resourcefulness, power, inspired action\nThe Magician card is numbered One – the number of new beginnings and opportunities – and associates with the planet of Mercury. He stands with one arm stretched upwards towards the Universe, and the other pointing down to the earth. His positioning represents his connection between the spiritual realms and the material realms. The Magician uses this relationship to create and manifest his goals in the physical realm. He is the conduit that converts energy into matter. The Magician’s robe is white, symbolising purity, and his cloak is red, representing worldly experience and knowledge.\n\nOn the table in front of him are the four symbols of the Tarot suits – a cup, pentacle, sword and wand – each symbolising one of the four elements – water, earth, air and fire. It is also a sign that he has all the tools (and elements) he needs to manifest his intentions into being. Above his head is the infinity symbol, and around his waist is a snake biting its own tail – both of which signal that he has access to unlimited potential. And in the foreground is an array of foliage and flowers, symbolising the blossoming and fruition of his ideas and aspirations.\n\n\n");
            break;
        case 3:
            printf("The High Priestess\nIntuition, sacred knowledge, divine feminine, the subconscious mind\nThe High Priestess sits in front of a thin veil decorated with pomegranates. The veil represents the separate conscious and subconscious realms, the seen and the unseen, and serves to keep casual onlookers out. Only the initiated may enter. The pomegranates on the veil are a symbol of abundance, fertility and the divine feminine, and are sacred to Persephone who ate a pomegranate seed in the underworld and was forced to return every year.\n\nOn either side of the High Priestess stand two pillars, marking the entrance to this sacred, mystical temple (also associated with the Temple of Solomon). One pillar is black with the letter B (Boaz, meaning ‘in his strength’) and the other is white with the letter J (Jachin, meaning ‘he will establish’). The black and white colours of the pillars symbolise duality – masculine and feminine, darkness and light – stating that knowledge and acceptance of duality are required to enter this sacred space.\n\nThe High Priestess wears a blue robe with a cross on her chest and a horned diadem (or crown), both a symbol of her divine knowledge and her status as a divine ruler. In her lap, she holds a scroll with the letter TORA, signifying the Greater Law (according to A. E. Waite). It is partly covered, signifying that this sacred knowledge is both explicit and implicit, it will only be revealed when the student is ready to look beyond the material realm. The crescent moon at her feet symbolises her connection with the divine feminine, her intuition and subconscious mind, and the natural cycles of the moon.\n\n\n");
            break;
        case 4:
            printf("The Empress\nFemininity, beauty, nature, nurturing, abundance\nThe Empress is a beautiful, full-figured woman with blonde hair and a peaceful aura about her. On her head, she wears a crown of twelve stars, showing her connection with the mystical realm and the cycles of the natural world (the twelve months of the year and the twelve planets). Her robe is patterned with pomegranates, symbolic of fertility, and sits upon a luxurious array of cushions and flowing red velvet. One cushion features the symbol of Venus, the planet of love, creativity, fertility, beauty and grace – the essence of the Empress.\n\nA beautiful, lush forest and winding stream surround the Empress, signifying her connection with Mother Earth and life itself. She draws her sense of peace from the trees and the water and is rejuvenated by the energy of nature. In the foreground, golden wheat springs from the soil, reflecting abundance from a recent harvest.\n\n\n");
            break;
        case 5:
            printf("The Emperor\nAuthority, establishment, structure, a father figure\nIf the Empress is the Mother archetype of the Tarot deck, the Emperor is the Father. He sits upon a large stone throne, adorned with four rams’ heads (symbolic of his connection with Aries and the planet Mars). In his right hand, the Emperor holds an ankh, the Egyptian symbol of life, and in his left is an orb representing the world over which he rules.\n\nHe wears a red robe, indicative of his power, passion and energy for life. Underneath it, he wears a suit of armour, suggesting that he is protected from any threat (and any emotional response or vulnerability). His long white beard is symbolic of his age-old wisdom and experience, and along with his gold crown, he is an authority figure who demands to be heard.\n\nBehind his throne looms a tall, impenetrable mountain range, signifying that he is backed by a solid foundation but resistant to making any changes unless he deems it necessary. Beneath the peaks flows a small river, giving some hope that despite his tough exterior, he is still an emotional being – it will just take a lot of digging and trust to open him up to his softer side.\n\n\n");
            break;
        case 6:
            printf("The Heirophant\nSpiritual wisdom, religious beliefs, conformity, tradition,institutions\nThe Hierophant is the masculine counterpart to the High Priestess. He is also known as the Pope or the Teacher in other Tarot decks and is ruled by Taurus.\n\nThe Hierophant is a religious figure sitting between two pillars of a sacred temple – though this temple differs from the one in which the High Priestess sits. He wears three robes – red, blue and white – and a three-tiered crown, both representing the three worlds over which he rules (the conscious, sub-conscious and super-conscious). In his left hand, he holds the Papal Cross, a triple sceptre that signifies his religious status. He raises his right hand in a religious blessing, with two fingers pointing towards Heaven and two towards Earth.\n\nBefore him kneel two followers. The Hierophant’s task is to pass down his spiritual wisdom and initiate the two into the church so they can take up their appointed roles. This imagery speaks to a shared group identity and a rite of passage to enter the next level. The crossed keys at the Hierophant’s feet represent the balance between the conscious and subconscious minds and the unlocking of mysteries, which only he can teach.\n\n\n");
            break;
        case 7:
            printf("The Lovers\nLove, harmony, relationships, values alignment, choices\nThe Lovers card shows a naked man and woman standing beneath the angel, Raphael, whose name means ‘God heals’ and represents both physical and emotional healing. The angel blesses the man and woman and reminds them of their union with the Divine.\n\nThe couple stands in a beautiful, fertile landscape, reminiscent of the Garden of Eden. Behind the woman stands a tall apple tree, with a snake winding its way up the trunk. The serpent and apple tree represent the temptation of sensual pleasures that may take one’s focus away from the Divine. Behind the man is a tree of flames, which represent passion, the primary concern of the man. The twelve flames suggest the twelve zodiac signs, the symbol of time and eternity. The man looks to the woman, who watches the angel, showing the path of the conscious to the subconscious to the super-conscious, or from physical desire to emotional needs to spiritual concerns.\n\nThe volcanic mountain in the background is rather phallic and represents the eruption of passion that happens when man and woman meet in full frontal nudity.\n\n\n");
            break;
        case 8:
            printf("The Chariot\nControl, willpower, success, action, determination\nThe Chariot Tarot card shows a brave warrior standing inside a chariot. He wears armour decorated with crescent moons (representing what is coming into being), a tunic with a square (the strength of will) and other alchemical symbols (spiritual transformation). The laurel and star crown signals victory, success and spiritual evolution. Although he appears to be driving the chariot, the charioteer holds no reins – just a wand like the Magician’s – symbolising that he controls through the strength of his will and mind.\n\nThe charioteer stands tall – there’s no sitting down for this guy, as he’s all about taking action and moving forward. Above his head is a canopy of six-pointed stars, suggesting his connection to the celestial world and the Divine will. In front of the vehicle sit a black and a white sphinx, representing duality, positive and negative and, at times, opposing forces. Note how the sphinxes are pulling in opposite directions, but the charioteer uses his willpower and sheer resolve to steer the chariot forward in the direction he wants.\n\nBehind the chariot flows a wide river, symbolic of the need to be ‘in flow’ with the rhythm of life while also charging ahead toward your goals and intentions.\n\n\n");
            break;
        case 9:
            printf("Strength\nStrength, courage, persuasion, influence, compassion\nIn the Strength Tarot card, a woman gently strokes a lion on its forehead and jaw. Even though it is known for its ferociousness, the woman has tamed this wild beast with her calming, loving energy. The lion is a symbol of raw passions and desires, and in taming him, the woman shows that animal instinct and raw passion can be expressed in positive ways when inner strength and resilience are applied. She doesn’t use force or coercion; she channels her inner strength to subdue and subtly control the lion.\n\nThe woman wears a white robe, showing her purity of spirit, and a belt and crown of flowers that represent the fullest, most beautiful expression of nature. Over her head is the symbol of infinity, representing her infinite potential and wisdom.\n\n\n");
            break;
        case 10:
            printf("The Hermit\nSoul-searching, introspection, being alone, inner guidance\nThe Hermit stands alone on the top of a mountain. The snow-capped range symbolises his spiritual mastery, growth and accomplishment. He has chosen this path of self-discovery and, as a result, has reached a heightened state of awareness.\n\nIn his right hand, he holds a lantern with a six-pointed star inside; it is the Seal of Solomon, a symbol of wisdom. As the Hermit walks his path, the lamp lights his way – but it only illuminates his next few steps rather than the full journey. He must step forward to see where to go next, knowing that not everything will be revealed at once. In his left hand, the side of the subconscious mind, the Hermit holds a long staff (a sign of his power and authority), which he uses to guide and balance him.\n\n\n");
            break;
        case 11:
            printf("Wheel of Fortune\nGood luck, karma, life cycles, destiny, a turning point\nThe Wheel of Fortune card shows a giant wheel, with three figures on the outer edges. Four Hebrew letters – YHVH (Yod Heh Vau Heh), the unpronounceable name of God – are inscribed on the wheel’s face. There are also the letters TORA, thought to be a version of the word Torah, meaning ‘law’, or TAROT, or even ROTA (Latin for ‘wheel’). The middle wheel has the alchemical symbols for mercury, sulphur, water and salt – the building blocks of life and the four elements – and represents formative power.\n\nOn the outer circle is a snake, the Egyptian god Typhon (the god of evil), descending on the left side. The snake also represents the life force plunging into the material world. On the right side rises the Anubis, the Egyptian God of the dead who welcomes souls to the underworld. And on top of the wheel sits the Sphinx, representing knowledge and strength.\n\nIn the corners of the Wheel of Fortune card are four winged creatures, each associated with the four fixed signs of the Zodiac: the angel is Aquarius, the eagle is Scorpio, the lion is Leo, and the bull is Taurus. Their wings signify stability amidst movement and change, and each holds the Torah, representing wisdom.\n\n\n");
            break;
        case 12:
            printf("Justice\nJustice, fairness, truth, cause and effect, law\nThe figure of Justice sits in front of a loosely hung purple veil, signifying compassion, and between two pillars, similar to those framing the High Priestess and the Hierophant, which symbolise balance, law and structure.\n\nShe holds a sword in her right hand, showing the logical, well-ordered mindset necessary to dispense fair justice. The sword points upwards – expressing a firm and final decision – and the double-edged blade signifies that our actions always carry consequences. The scales in her left (intuitive) hand, show intuition must balance that logic and are a symbol of her impartiality. Justice wears a crown with a small square on it representing well-ordered thoughts, and a red robe with a green mantle. A little white shoe pops out from beneath her clothing as a reminder of the spiritual consequences of your actions.\n\n\n");
            break;
        case 13:
            printf("The Hanged Man\nPause, surrender, letting go, new perspectives\nThe Hanged Man shows a man suspended from a T-shaped cross made of living wood. He is hanging upside-down, viewing the world from a completely different perspective, and his facial expression is calm and serene, suggesting that he is in this hanging position by his own choice. He has a halo around his head, symbolising new insight, awareness and enlightenment. His right foot is bound to the tree, but his left foot remains free, bent at the knee and tucked in behind his right leg. His arms are bent, with hands held behind his back, forming an inverted triangle. The man is wearing red pants representing human passion and the physical body, and a blue vest for knowledge. The Hanged Man is the card of ultimate surrender, of being suspended in time and of martyrdom and sacrifice to the greater good.\n\n\n");
            break;
        case 14:
            printf("Death\nEndings, change, transformation, transition\nThe Death card shows the Messenger of Death – a skeleton dressed in black armour, riding a white horse. The skeleton represents the part of the body which survives long after life has left it; the armour symbolises invincibility and that death will come no matter what. Its dark colour is that of mourning and the mysterious, while the horse is the colour of purity and acts as a symbol of strength and power. Death carries a black flag decorated with a white, five-petal rose, reflecting beauty, purification and immortality and the number five representing change. Together, these symbols reveal that death isn’t just about life ending. Death is about endings and beginnings, birth and rebirth, change and transformation. There is beauty in death, and it is an inherent part of being alive.\n\nA royal figure appears to be dead on the ground, while a young woman, child and bishop plead with the skeletal figure to spare them. But, as we all know, death spares no one.\n\nIn the background, a boat floats down the river, akin to the mythological boats escorting the dead to the afterlife. On the horizon, the sun sets between two towers (which also appear in the Moon Tarot card), in a sense dying each night and being reborn every morning.\n\n\n");
            break;
        case 15:
            printf("Temperance\nBalance, moderation, patience, purpose\nThe Temperance card shows a large, winged angel who is both masculine and feminine. She wears a light blue robe with a triangle enclosed in a square on the front, representing that humans (the triangle) are bound by the Earth and natural law (square). The angel balances between one foot on the rocks, expressing the need to stay grounded, and one foot in the water, showing the need to be in flow. She pours water between two cups, symbolic of the flow and alchemy of life.\n\nIn the background, there is a winding path up to a mountain range, reflecting the journey through life. Above the mountains hovers a golden crown encased in a glowing light, a symbol of taking the Higher path and staying true to one’s life purpose and meaning.\n\n\n");
            break;
        case 16:
            printf("The Devil\nShadow self, attachment, addiction, restriction, sexuality\nThe Devil card shows Baphomet, or the Horned Goat of Mendes, a creature that is half man, half goat. Baphomet originally represented the balance between good and evil, male and female, and human and animal; however, more recently, this figure has been linked to the occult and has become a scapegoat for all things considered ‘evil’.\n\nThe Devil has the wings of a vampire bat, an animal that sucks the lifeblood out of its prey, symbolic of what happens when you give in to your raw desires. He has a hypnotic stare which ‘magnetises’ and entrances those who come near him, bringing them under his power. Above him is an inverted pentagram – a sign of the darker side of magic and occultism. He raises his right hand in the Vulcan Salute – a Jewish blessing, later made famous by the film series, Star Trek. In his left hand, he holds a lit torch.\n\nAt the foot of the Devil stand a man and a woman, both naked and chained to the podium on which the Devil sits. They appear to be held here against their will – but look closer, and you will notice that the chains around their necks are loose and could be easily removed. Each has small horns on their head, like the devil’s, a sign that they are becoming increasingly like him the longer they stay here. Both have tails, a further symbol of their animalistic tendencies and raw instincts, and the grapes and the fire on their respective tails signify pleasure and lust.\n\n\n");
            break;
        case 17:
            printf("The Tower\nSudden change, upheaval, chaos, revelation, awakening\nThe Tower shows a tall tower perched on the top of a rocky mountain. Lightning strikes set the building alight, and two people leap from the windows, head first and arms outstretched. It is a scene of chaos and destruction.\n\nThe Tower itself is a solid structure, but because it has been built on shaky foundations, it only takes one bolt of lightning to bring it down. It represents ambitions and goals made on false premises.\n\nThe lightning represents a sudden surge of energy and insight that leads to a break-through or revelation. It enters via the top of the building and knocks off the crown, symbolising energy flowing down from the Universe, through the crown chakra. The people are desperate to escape from the burning building, not knowing what awaits them as they fall. Around them are 22 flames, representing the 12 signs of the zodiac and 10 points of the Tree of Life, suggesting that even in times of disaster, there is always divine intervention.\n\n\n");
            break;
        case 18:
            printf("The Star\nHope, faith, purpose, renewal, spirituality\nThe Star card shows a naked woman kneeling at the edge of a small pool. She holds two containers of water: one in her left hand (the subconscious) and one in her right (the conscious). She pours the water out to nourish the earth and to continue the cycle of fertility, represented by the lush greenery around her. The other container pours the water onto dry land in five rivulets, representing the five senses.\n\nThe woman has one foot on the ground, representing her practical abilities and good common sense, and the other foot in the water, representing her intuition and inner resources and listening to her inner voice. She is naked, representing her vulnerability and purity under the vastness of the starry night sky. Behind her shines one large star, representing her core essences, and seven smaller stars, representing the chakras.\n\n\n");
            break;
        case 19:
            printf("The Moon\nIllusion, fear, anxiety, subconscious, intuition\nThe Moon card shows a full moon in the night’s sky, positioned between two large towers. The Moon is a symbol of intuition, dreams, and the unconscious. Its light is dim compared to the sun, and only slightly illuminates the path to higher consciousness winding between the two towers.\n\nIn the foreground is a small pool, representing the watery, subconscious mind. A small crayfish crawls out of the pool, symbolising the early stages of consciousness unfolding. A dog and a wolf stand in the grassy field, howling at the moon, representing both the tamed and the wild aspects of our minds.\n\n\n");
            break;
        case 20:
            printf("The Sun\nPositivity, fun, warmth, success, vitality\nThe Sun Tarot card radiates with optimism and positivity. A large, bright sun shines in the sky, representing the source of all life on Earth. Underneath, four sunflowers grow tall above a brick wall, representing the four suits of the Minor Arcana and the four elements.\n\nIn the foreground, a young, naked child is sitting on top of a calm white horse. The child represents the joy of being connected with your inner spirit, and his nakedness is a sign he has nothing to hide and has all the innocence and purity of childhood. The white horse is also a sign of purity and strength.\n\n\n");
            break;
        case 21:
            printf("Judgement\nJudgement, rebirth, inner calling, absolution\nThe Judgement card shows naked men, women, and children rising from their graves, arms outspread and looking up into the sky. Above, Archangel Gabriel – the Messenger of God – blows his trumpet. The people respond to his call, ready to be judged and to find out if they will be accepted into the heavens or not. In the background is an extensive mountain range, signifying the insurmountable obstacles and the impossibility of avoiding judgement.\n\n\n");
            break;
            printf("The World\nCompletion, integration, accomplishment, travel\nThe World card shows a naked woman wrapped in a purple cloth, dancing inside a large laurel wreath. She looks behind her to the past, while her body moves forward to the future. In her hands are two wands or batons, like the one the Magician holds. It is a symbol that what was manifested with the Magician has now come to completion with the World. The wreath is circular, symbolising a continual cycle of successful completion and new beginnings because, as the woman steps through the wreath, she is completing one phase but beginning another one almost straight away.\n\nAround the wreath are four figures (a lion, bull, cherub and eagle), similar to those in the Wheel of Fortune. Both the World and the Wheel of Fortune speak to the cyclical nature of your life and your progression through its cycles. The four figures represent the four fixed signs of the Zodiac—Leo, Taurus, Aquarius, and Scorpio. They are symbolic of the four elements, the four suits of the Tarot, four compass points, four seasons, and the four corners of the Universe. They are here to guide you from one phase to the next, bringing balance and harmony to your journey.\n\n\n");
            break;
    }
}
