from django.shortcuts import render
from accounts.models import *
from django.http import HttpResponseRedirect
# Create your views here.


def index(request):
    movies = Movie.objects.all()
    context = {
        'mov': movies
    }
    return render(request,"index.html", context)

def movies(request, id):
    movies = Movie.objects.get(movie=id)
    cin = Cinema.objects.filter(cinema_show__movie=movies).prefetch_related('cinema_show').distinct()  # get all cinema
    show = Shows.objects.filter(movie=id)
    context = {
        'movies':movies,
        'show':show,
        'cin':cin,
    }
    return render(request, "movies.html", context )

def seat(request, id):
    show = Shows.objects.get(shows=id)
    seat = Bookings.objects.filter(shows=id)
    seat=list(seat).sort()
    return render(request,"seat.html", {'show':show, 'seat':seat})    

def booked(request):
    if request.method == 'POST':
        user = request.user
        seat = request.POST.get('SeatNo.')
        show = request.POST['show']
        total_seats1 = request.POST['TotalSeats']
        book = Bookings(useat=seat, shows_id=show, user=user, total_seats=total_seats1)
        book.save()
        return render(request,"booked.html", {'book':book})
        

def ticket(request, id):
    ticket = Bookings.objects.get(id=id)
    count=0
    for seat in ticket.useat:
        if seat=='#':
            count=count+1
    price=ticket.shows.price*count
    return render(request,"ticket.html", {'ticket':ticket,'price':price})

