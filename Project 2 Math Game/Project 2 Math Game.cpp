#include <iostream>
using namespace std;

enum enQuestionLevel{Easy=1,Med=2,Hard=3,QMix=4};

enum enOperationType{Add=1,Sub=2,Mul=3,Div=4,Mix=5};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

struct stFinalGame
{

    short NumberOfQuestions = 0;
    enQuestionLevel QuestionsLevel;
    enOperationType OperationType;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;

};

string NameQuestionLevel(enQuestionLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
    case enQuestionLevel::Easy:
        return "Easy";
        break;
    case enQuestionLevel::Med:
        return "Med";
        break;
    case enQuestionLevel::Hard:
        return "Hard";
        break;
    case enQuestionLevel::QMix:
        return "Mix";
        break;
    }

}

string NameOperationType(enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:
        return "+";
        break;
    case enOperationType::Sub:
        return "-";
        break;
    case enOperationType::Mul:
        return "*";
        break;
    case enOperationType::Div:
        return "/";
        break;
    case enOperationType::Mix:
        return "Mix";
        break;
    }
}

short easy()
{
	return (short)RandomNumber(0, 20);
}

short med()
{
	return(short) RandomNumber(21, 60);
}

short hard()
{
	return(short) RandomNumber(61, 100);
}

short mix()
{
    short mix=RandomNumber(1, 3);
    switch (mix)
    {
    case 1:
        return easy();
        break;
    case 2:
        return  med();
        break;
    case 3:
        return hard();
        break;

    }

}

short HowManyQuestion()
{
    short Question;
    do 
    {
        cout << "How Many Questions do you want to answer ? ";
        cin >> Question;
    } while (Question < 1 || Question>1e3);
    return Question;
}


enQuestionLevel SetQuestionsLevel()
{
    short Question;
    do {
        cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin >> Question;

    } while (Question < 1 || Question>4);
    return (enQuestionLevel)Question;
}

enOperationType SetOperationsType()
{
    short Operation;
    do {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin >> Operation;
    } while (Operation < 1 || Operation>5);
    return (enOperationType)Operation;
}

short GetNumberQuestionLevel(enQuestionLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
    case enQuestionLevel::Easy:
        return easy();
        break;
    case enQuestionLevel::Med:
        return  med();
        break;
    case enQuestionLevel::Hard:
        return hard();
        break;
    case enQuestionLevel::QMix:
        return mix();
        break;
    }
}

char MixOperation()
{
    int mix = RandomNumber(1, 4);
    switch (mix)
    {
    case 1:
        return '+';
        break;
    case 2:
        return '-';
        break;
    case 3:
        return '*';
        break;
    case 4:
        return '/';
        break;
    }

}

char GetOperation(enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:
        return '+';
        break;
    case enOperationType::Sub:
        return '-';
        break;
    case enOperationType::Mul:
        return '*';
        break;
    case enOperationType::Div:
        return '/';
        break;
    case enOperationType::Mix:
        return MixOperation();
        break;
    }


}

void showQuestion(short Number1,short Number2,char Operation)
{
    cout << Number1 << "\n" << Number2 << " " << Operation << endl;
    cout << "\n_____________\n";

}

short ResultTrueAnser(short Number1, short Number2, char Operation)
{
    switch (Operation)
    {
    case '-':
            return Number1 - Number2;
        break;
    case '+':
        return Number1 + Number2;
        break;
    case '*':
        return Number1 * Number2;
        break;
    case '/':
        return Number1 / Number2;;
        break;
    }
    
}

bool CheicResultAnswer(short Result,short ans)
{
    return Result == ans;
}

stFinalGame FillInfoGame(short NumberOfQuestions ,enQuestionLevel QuestionsLevel,enOperationType OperationType,short NumberOfRightAnswers,short NumberOfWrongAnswers)
{
    stFinalGame FinalGame;
    FinalGame.NumberOfQuestions = NumberOfQuestions;
    FinalGame.QuestionsLevel = QuestionsLevel;
    FinalGame.OperationType = OperationType;
    FinalGame.NumberOfRightAnswers = NumberOfRightAnswers;
    FinalGame.NumberOfWrongAnswers = NumberOfWrongAnswers;

    return FinalGame;
}

void ShowRigtAnser()
{
    system("color 2F");
    cout << "Right Answer :-)\n\n";
}
void ShowWorngAnser(short ansTrue)
{
    system("color 4F");
    cout << "\aWorng Anser :-(\n";
    cout << "The right anser is: " << ansTrue << "\n\n";
}
stFinalGame PlayGame(short HowManyQuestion)
{
    enQuestionLevel  QuestionLevel = SetQuestionsLevel();
    enOperationType OperationType = SetOperationsType();
    short NumberOfRightAnswers = 0, NumberOfWrongAnswers = 0;
    for (int Question = 1; Question <= HowManyQuestion; Question++)
    {
        cout << "\nQuestion [" << Question << "/" << HowManyQuestion << "]\n\n";
        short Number1= GetNumberQuestionLevel(QuestionLevel), Number2= GetNumberQuestionLevel(QuestionLevel);
        char Operation = GetOperation(OperationType);
        short ansTrue = ResultTrueAnser(Number1, Number2, Operation);;
        showQuestion(Number1, Number2, Operation);

        short Result;
        cin >> Result;

        if (CheicResultAnswer(Result, ansTrue))
        {
            ShowRigtAnser();
            NumberOfRightAnswers++;
        }
        else
        {
            ShowWorngAnser(ansTrue);
            NumberOfWrongAnswers++;
        }

    }
    return FillInfoGame(HowManyQuestion, QuestionLevel, OperationType, NumberOfRightAnswers, NumberOfWrongAnswers);
}

void ShowPass()
{
    cout << "_______________________________________\n";
    cout << "\n Final Results is PASS :-)\n";
    cout << "\n_______________________________________\n\n";
}

void ShowFail()
{
    cout << "_______________________________________\n";
    cout << "\n Final Results is Fail :-)\n";
    cout << "\n_______________________________________\n\n";
}

void showFinalGame(stFinalGame FinalGame)
{
    cout << "Number Of Questions: " << FinalGame.NumberOfQuestions << endl;
    cout << "Questions Level    : " << NameQuestionLevel(FinalGame.QuestionsLevel) << endl;
    cout << "OpType             : " << NameOperationType( FinalGame.OperationType )<< endl;
    cout << "Number Of Right Answers: " << FinalGame.NumberOfRightAnswers << endl;
    cout << "Number Of Wrong Answers: " << FinalGame.NumberOfWrongAnswers << endl;
    cout << "\n____________________________________________\n";
}

void ResetScreen()
{
    system("cls");
    system("color 0F");

}

void StartGame()
{

    char PlayAgain = 'y';
    do {


        ResetScreen();
        stFinalGame FinalGame = PlayGame(HowManyQuestion());
        if (FinalGame.NumberOfRightAnswers > FinalGame.NumberOfWrongAnswers)
        {
            system("color 2F");
            ShowPass();
        }
        else
        {
            system("color 4F");
            ShowFail();
        }
        showFinalGame(FinalGame);




        cout << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();



}

