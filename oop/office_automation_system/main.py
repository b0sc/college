class Email:
    def __init__(self, sender, recipient, subject, content):
        self.sender = sender
        self.recipient = recipient
        self.subject = subject
        self.content = content

    def send_email(self):
        print(f"Email sent from {self.sender} to {self.recipient}")

class CalendarEvent:
    def __init__(self, title, date, location):
        self.title = title
        self.date = date
        self.location = location

    def schedule_event(self):
        print(f"Event '{self.title}' scheduled on {self.date} at {self.location}")

# Usage
email = Email("user@example.com", "recipient@example.com", "Meeting", "Discuss project updates")
email.send_email()

event = CalendarEvent("Team Meeting", "2024-01-15 10:00 AM", "Conference Room")
event.schedule_event()