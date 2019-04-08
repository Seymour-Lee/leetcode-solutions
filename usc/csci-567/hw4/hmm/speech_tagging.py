import numpy as np
import time
import random
from hmm import HMM


def accuracy(predict_tagging, true_tagging):
	if len(predict_tagging) != len(true_tagging):
		return 0, 0, 0
	cnt = 0
	for i in range(len(predict_tagging)):
		if predict_tagging[i] == true_tagging[i]:
			cnt += 1
	total_correct = cnt
	total_words = len(predict_tagging)
	if total_words == 0:
		return 0, 0, 0
	return total_correct, total_words, total_correct*1.0/total_words


class Dataset:

	def __init__(self, tagfile, datafile, train_test_split=0.8, seed=int(time.time())):
		tags = self.read_tags(tagfile)
		data = self.read_data(datafile)
		self.tags = tags
		lines = []
		for l in data:
			new_line = self.Line(l)
			if new_line.length > 0:
				lines.append(new_line)
		if seed is not None: random.seed(seed)
		random.shuffle(lines)
		train_size = int(train_test_split * len(data))
		self.train_data = lines[:train_size]
		self.test_data = lines[train_size:]
		return

	def read_data(self, filename):
		"""Read tagged sentence data"""
		with open(filename, 'r') as f:
			sentence_lines = f.read().split("\n\n")
		return sentence_lines

	def read_tags(self, filename):
		"""Read a list of word tag classes"""
		with open(filename, 'r') as f:
			tags = f.read().split("\n")
		return tags

	class Line:
		def __init__(self, line):
			words = line.split("\n")
			self.id = words[0]
			self.words = []
			self.tags = []

			for idx in range(1, len(words)):
				pair = words[idx].split("\t")
				self.words.append(pair[0])
				self.tags.append(pair[1])
			self.length = len(self.words)
			return

		def show(self):
			print(self.id)
			print(self.length)
			print(self.words)
			print(self.tags)
			return


# TODO:
def model_training(train_data, tags):
	"""
	Train HMM based on training data

	Inputs:
	- train_data: (1*num_sentence) a list of sentences, each sentence is an object of line class
	- tags: (1*num_tags) a list of POS tags

	Returns:
	- model: an object of HMM class initialized with parameters(pi, A, B, obs_dict, state_dict) you calculated based on train_data
	"""
	# model = None
	###################################################
	# Edit here
	###################################################
	# print(train_data)
	# print(tags)
	obs = set([])
	states = set([])
	obs2times = {}
	state2times = {}
	obs_total = 0
	state_total = 0
	for line in train_data:
		for w in line.words:
			obs.add(w)
			if w in obs2times:
				obs2times[w] += 1
			else:
				obs2times[w] = 1
			obs_total += 1
		for t in line.tags:
			states.add(t)
			if t in state2times:
				state2times[t] += 1
			else:
				state2times[t] = 1
			state_total += 1
	# print(words)
	obs_dict = {}
	i = 0
	for w in obs:
		obs_dict[w] = i
		i += 1

	state_dict = {}
	i = 0
	for t in states:
		state_dict[t] = i
		i += 1
	# print(obs_dict)
	# print(state_dict)
	obs_dict_size = len(obs_dict)
	state_dict_size = len(state_dict)
	# print(obs_dict_size, state_dict_size)
	pi = np.ones([state_dict_size+1], dtype="float")
	A = np.ones([state_dict_size+1, state_dict_size+1], dtype="float")
	B = np.ones([state_dict_size+1, obs_dict_size+1], dtype="float")

	
	"""
	- pi: (1*num_state) A numpy array of initial probabilities. pi[i] = P(Z_1 = s_i)
	- A: (num_state*num_state) A numpy array of transition probabilities. A[i, j] = P(Z_t = s_j|Z_t-1 = s_i)
	- B: (num_state*num_obs_symbol) A numpy array of observation probabilities. B[i, k] = P(O_t = x_k| Z_t = s_i)
	- obs_dict: (num_obs_symbol*1) A dictionary mapping each observation symbol to their index in B
	- state_dict: (num_state*1) A dictionary mapping each state to their index in pi and A
	"""
	# pi: (1*num_state) A numpy array of initial probabilities. pi[i] = P(Z_1 = s_i)
	pi_counter = 0.0
	for line in train_data:
		c = line.tags[0]
		# print(c)
		# print(c in state_dict)
		pi[state_dict[c]] += 1.0
		pi_counter += 1.0
	for i in range(len(pi)):
		pi[i] = float(pi[i]) / float(pi_counter)

	# A: (num_state*num_state) A numpy array of transition probabilities. A[i, j] = P(Z_t = s_j|Z_t-1 = s_i)
	for line in train_data:
		for i in range(0, len(line.tags)-1, 1):
			# the following line exists accumulation error
			A[state_dict[line.tags[i]]][state_dict[line.tags[i+1]]] += 1.0 / float(state2times[line.tags[i]])

	# B: (num_state*num_obs_symbol) A numpy array of observation probabilities. B[i, k] = P(O_t = x_k| Z_t = s_i)
	for line in train_data:
		for i in range(len(line.words)):
			o = line.words[i]
			s = line.tags[i]
			B[state_dict[s]][obs_dict[o]] += 1.0 / float(obs2times[o])

	model = HMM(pi, A, B, obs_dict, state_dict)
	# print(len(model.obs_dict))
	return model


# TODO:
def speech_tagging(test_data, model, tags):
	"""
	Inputs:
	- test_data: (1*num_sentence) a list of sentences, each sentence is an object of line class
	- model: an object of HMM class

	Returns:
	- tagging: (num_sentence*num_tagging) a 2D list of output tagging for each sentences on test_data
	"""
	tagging = []
	###################################################
	# Edit here
	###################################################
	# print(model[0])
	
	for line in test_data:
		curtag = model.viterbi(line.words)
		tagging.append(curtag)
	return tagging

