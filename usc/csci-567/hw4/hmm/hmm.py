from __future__ import print_function
import numpy as np


class HMM:

    def __init__(self, pi, A, B, obs_dict, state_dict):
        """
        - pi: (1*num_state) A numpy array of initial probabilities. pi[i] = P(Z_1 = s_i)
        - A: (num_state*num_state) A numpy array of transition probabilities. A[i, j] = P(Z_t = s_j|Z_t-1 = s_i)
        - B: (num_state*num_obs_symbol) A numpy array of observation probabilities. B[i, k] = P(O_t = x_k| Z_t = s_i)
        - obs_dict: (num_obs_symbol*1) A dictionary mapping each observation symbol to their index in B
        - state_dict: (num_state*1) A dictionary mapping each state to their index in pi and A
        """
        self.pi = pi
        self.A = A
        self.B = B
        self.obs_dict = obs_dict
        self.state_dict = state_dict

    # TODO
    def forward(self, Osequence):
        """
        Inputs:
        - self.pi: (1*num_state) A numpy array of initial probailities. pi[i] = P(Z_1 = s_i)
        - self.A: (num_state*num_state) A numpy array of transition probailities. A[i, j] = P(Z_t = s_j|Z_t-1 = s_i)
        - self.B: (num_state*num_obs_symbol) A numpy array of observation probabilities. B[i, k] = P(O_t = x_k| Z_t = s_i)
        - Osequence: (1*L) A numpy array of observation sequence with length L

        Returns:
        - delta: (num_state*L) A numpy array delta[i, t] = P(Z_t = s_i, x_1:x_t | λ)
        """
        S = len(self.pi)
        L = len(Osequence)
        delta = np.zeros([S, L])
        ###################################################
        # Edit here
        ###################################################
        for i in range(S):
            delta[i, 0] = self.pi[i] * self.B[i, self.obs_dict[Osequence[0]]]

        for i in range(1, L):
            for j in range(S):
                delta[j, i] = self.B[j, self.obs_dict[Osequence[i]]] * sum([self.A[k,j] * delta[k,i-1] for k in range(S)])
        return delta

    # TODO:
    def backward(self, Osequence):
        """
        Inputs:
        - self.pi: (1*num_state) A numpy array of initial probailities. pi[i] = P(Z_1 = s_i)
        - self.A: (num_state*num_state) A numpy array of transition probailities. A[i, j] = P(Z_t = s_j|Z_t-1 = s_i)
        - self.B: (num_state*num_obs_symbol) A numpy array of observation probabilities. B[i, k] = P(O_t = x_k| Z_t = s_i)
        - Osequence: (1*L) A numpy array of observation sequence with length L

        Returns:
        - gamma: (num_state*L) A numpy array gamma[i, t] = P(x_t+1:x_T | Z_t = s_i, λ)
        """
        S = len(self.pi)
        L = len(Osequence)
        gamma = np.zeros([S, L])
        ###################################################
        # Edit here
        ###################################################
        for j in range(S):
            gamma[j,L-1]=1
        
        for t in range(L-2,-1,-1):
            for k in range(S):
                gamma[k,t]= sum([gamma[j,t+1]* self.A[k,j] * self.B[j,self.obs_dict[Osequence[t+1]]] for j in range(S)])
        return gamma

    # TODO:
    def sequence_prob(self, Osequence):
        """
        Inputs:
        - Osequence: (1*L) A numpy array of observation sequence with length L

        Returns:
        - prob: A float number of P(x_1:x_T | λ)
        """
        prob = 0
        ###################################################
        # Edit here
        ###################################################
        alpha = self.forward(Osequence)
        prob = sum(alpha[:,-1])
        return prob

    # TODO:
    def posterior_prob(self, Osequence):
        """
        Inputs:
        - Osequence: (1*L) A numpy array of observation sequence with length L

        Returns:
        - prob: (num_state*L) A numpy array of P(s_t = i | O, λ)
        """
        prob = 0
        ###################################################
        # Edit here
        ###################################################
        delta = self.forward(Osequence)
        gamma = self.backward(Osequence)
        p = self.sequence_prob(Osequence)
        prob = sum([delta[i,0] * self.pi[i] * self.B[i, self.obs_dict[Osequence[0]]] for i in range(len(self.pi))])
        return prob

    # TODO:
    def viterbi(self, Osequence):
        """
        Inputs:
        - Osequence: (1*L) A numpy array of observation sequence with length L

        Returns:
        - path: A List of the most likely hidden state path k* (return state instead of idx)
        """
        path = []
        ###################################################
        # Edit here
        ###################################################
        S = len(self.pi)
        N = len(Osequence)
        delta = np.zeros([S, N])
        paths = np.zeros([S, N], dtype="int")
        
        for j in range(S):
            delta[j, 0] = self.pi[j] * self.B[j, self.obs_dict[Osequence[0]]]
            paths[j, 0] = 0
        
        for t in range(1, N):
            for j in range(S):
                deltas = [delta[i, t - 1] * self.A[i, j] * self.B[j, self.obs_dict[Osequence[t]]] for i in range(S)]
                delta[j, t] = max(deltas)
                paths[j, t] = np.argmax(deltas)
        
        path.append(np.argmax(delta[:, -1]))
        for t in reversed(range(N - 1)):
            path.append(paths[path[-1], t])
        path = reversed(path)
        return path
